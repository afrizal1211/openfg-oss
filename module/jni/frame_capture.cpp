#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android/log.h>

#define LOG_TAG "OpenFG_Capture"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class FrameCapturer {
public:
    void captureFrame() {
        // Read framebuffer to texture
        GLint width = 0, height = 0;
        glGetIntegerv(GL_VIEWPORT, nullptr); // simplified
        LOGI("Capturing frame");
    }
};
