#include <dlfcn.h>
#include <vulkan/vulkan.h>
#include <android/log.h>

#define LOG_TAG "OpenFG_VK"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

typedef VkResult (*PFN_vkQueuePresentKHR)(VkQueue, const VkPresentInfoKHR*);

static PFN_vkQueuePresentKHR orig_vkQueuePresentKHR = nullptr;

VkResult hooked_vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
    LOGI("Vulkan present intercepted");
    if (orig_vkQueuePresentKHR) {
        return orig_vkQueuePresentKHR(queue, pPresentInfo);
    }
    return VK_ERROR_UNKNOWN;
}

void install_vulkan_hooks() {
    void* vk = dlopen("libvulkan.so", RTLD_LAZY);
    if (!vk) return;
    orig_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)dlsym(vk, "vkQueuePresentKHR");
    LOGI("Vulkan hooks setup");
}
