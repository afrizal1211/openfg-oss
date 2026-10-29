#include <GLES2/gl2.h>
#include <android/log.h>

#define LOG_TAG "OpenFG_FProc"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class FrameProcessor {
public:
    void processFrame() {
        LOGI("Processing frame");
    }
    
    void applyUpscaling() {
        LOGI("Applying upscaling");
    }
    
    void generateInterpolatedFrames() {
        LOGI("Generating interpolated frames");
    }
};
