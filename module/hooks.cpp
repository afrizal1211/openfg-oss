#include "hooks.h"
#include <dlfcn.h>
#include <android/log.h>
#include "third_party/dobby/include/dobby.h"

#define LOG_TAG "OpenFG_Hooks"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay, EGLSurface) = nullptr;

static EGLBoolean hooked_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    LOGI("Frame swap intercepted in pid=%d", getpid());
    // Frame processing pipeline
    if (orig_eglSwapBuffers) {
        return orig_eglSwapBuffers(dpy, surface);
    }
    return eglSwapBuffers(dpy, surface);
}

bool install_all_hooks() {
    void* egl = dlopen("libEGL.so", RTLD_LAZY);
    if (!egl) return false;
    
    orig_eglSwapBuffers = (decltype(orig_eglSwapBuffers))dlsym(egl, "eglSwapBuffers");
    if (!orig_eglSwapBuffers) return false;
    
    // Try to hook with Dobby
    DobbyHook((void*)orig_eglSwapBuffers, (void*)hooked_eglSwapBuffers, (void**)&orig_eglSwapBuffers);
    
    LOGI("EGL hooks installed with Dobby");
    return true;
}
