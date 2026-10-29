#include <jni.h>
#include <sys/types.h>
#include <unistd.h>
#include <android/log.h>
#include "hooks.h"
#include "config.h"

#define LOG_TAG "OpenFG_Clone"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" [[gnu::visibility("default")]] void zygisk_module_entry(void* handle) {
    LOGI("OpenFG_Clone: module entry pid=%d uid=%d", getpid(), getuid());
    install_all_hooks();
    install_vulkan_hooks();
}

extern "C" [[gnu::visibility("default")]] void zygisk_companion_entry(int fd) {
    LOGI("OpenFG_Clone: companion entry");
}
