#include <jni.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <dlfcn.h>
#include <android/log.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>

#define LOG_TAG "OpenFG_Clone"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

namespace zygisk {
    struct api_table {
        void* hookJniNativeMethods;
        void* plthook_register;
        void* plthook_exclude_file;
        void* plthook_refresh;
        void* connectCompanion;
        void* setOption;
        void* getModuleDir;
        void* getFlags;
    };
    
    class ModuleBase {
    public:
        virtual ~ModuleBase() {}
        virtual void onLoad(void* api, JNIEnv* env) {}
        virtual void preAppSpecialize(void* api, JNIEnv* env) {}
        virtual void postAppSpecialize(void* api, const JNIEnv* env) {}
        virtual void preServerSpecialize(void* api, JNIEnv* env) {}
        virtual void postServerSpecialize(void* api, const JNIEnv* env) {}
    };
}

static void* (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface) = nullptr;

static EGLBoolean hooked_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    LOGI("eglSwapBuffers hooked in pid=%d", getpid());
    // TODO: Intercept frames here
    if (orig_eglSwapBuffers) {
        return orig_eglSwapBuffers(dpy, surface);
    }
    return eglSwapBuffers(dpy, surface);
}

static bool install_hooks() {
    void* egl_handle = dlopen("libEGL.so", RTLD_LAZY);
    if (!egl_handle) {
        LOGE("Failed to dlopen libEGL.so");
        return false;
    }
    
    void* sym = dlsym(egl_handle, "eglSwapBuffers");
    if (!sym) {
        LOGE("Failed to find eglSwapBuffers");
        return false;
    }
    
    LOGI("Found eglSwapBuffers at %p", sym);
    // Hook installation would go here (using Dobby/plthook)
    // For now just store original
    orig_eglSwapBuffers = (decltype(orig_eglSwapBuffers))sym;
    
    return true;
}

extern "C" [[gnu::visibility("default")]] void zygisk_module_entry(void* handle) {
    LOGI("OpenFG_Clone: zygisk_module_entry called, pid=%d uid=%d", getpid(), getuid());
    install_hooks();
}

extern "C" [[gnu::visibility("default")]] void zygisk_companion_entry(int fd) {
    LOGI("OpenFG_Clone: zygisk_companion_entry called");
}
