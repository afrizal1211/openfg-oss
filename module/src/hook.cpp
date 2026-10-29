#include <dlfcn.h>
#include <android/log.h>
#include <sys/mman.h>
#include <unistd.h>

#define LOG_TAG "OpenFG_Hook"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
