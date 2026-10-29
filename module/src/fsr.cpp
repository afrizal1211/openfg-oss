#include <GLES3/gl3.h>
#include <android/log.h>

#define LOG_TAG "OpenFG_FSR"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

void apply_fsr() {
    LOGI("Applying FSR upscaling");
}
