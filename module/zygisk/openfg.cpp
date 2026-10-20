#include "zygisk.hpp"
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "openfg", __VA_ARGS__)

class OpenFGModule : public zygisk::ModuleBase {
public:
    void onLoad(zygisk::Api *api, JNIEnv *env) override { LOGI("loaded"); }
    void preAppSpecialize(zygisk::Api *api, JNIEnv *env, zygisk::AppSpecializeArgs_v4 *args) override {}
    void postAppSpecialize(zygisk::Api *api, JNIEnv *env, const zygisk::AppSpecializeArgs_v4 *args) override {}
};

REGISTER_ZYGISK_MODULE(OpenFGModule)

extern "C" void companion_entry(int fd) {}
