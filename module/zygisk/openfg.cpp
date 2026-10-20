#include "zygisk.hpp"
#include <android/log.h>
#include <sys/types.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "openfg", __VA_ARGS__)

class OpenFGModule : public zygisk::ModuleBase {
public:
    void onLoad(zygisk::Api *api, JNIEnv *env) override { LOGI("loaded"); }
    void preAppSpecialize(zygisk::AppSpecializeArgs *args) override {}
    void postAppSpecialize(zygisk::Api *api, JNIEnv *env, const zygisk::AppSpecializeArgs *args) override {}
};

REGISTER_ZYGISK_MODULE(OpenFGModule)

extern "C" void companion_entry(int fd) {}
