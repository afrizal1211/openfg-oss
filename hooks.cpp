#include "hooks.h"
#include <dlfcn.h>
#include <android/log.h>

#define LOG_TAG "OpenFG_Hooks"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay, EGLSurface) = nullptr;

static EGLBoolean hooked_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    LOGI("Frame swap in pid=%d", getpid());
    // Frame processing would go here
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
    
    LOGI("EGL hooks installed");
    return true;
}
