#ifndef HOOKS_H
#define HOOKS_H

#include <EGL/egl.h>
#include <EGL/eglext.h>

bool install_all_hooks();
extern EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay, EGLSurface);

#endif
