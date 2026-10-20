#include <android/log.h>
#include <dlfcn.h>
#include <zygisk.h>
#include <string>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "openfg", __VA_ARGS__)

struct OpenFGModule : zygisk::ModuleBase {
    void onLoad(zygisk::Api *api, JNIEnv *env) override { LOGI("loaded"); }
    void preAppSpecialize(zygisk::Api *api, JNIEnv *env, AppConfig *cfg) override {
        // TODO: read /data/adb/openfg/packages.list; enable hooks only for selected pkgs
    }
    void postAppSpecialize(zygisk::Api *api, JNIEnv *env, const AppConfig *cfg) override {
        // TODO: install Dobby hooks on BufferQueueProducer::queueBuffer
    }
};

REGISTER_ZYGISK_MODULE(OpenFGModule)
REGISTER_ZYGISK_COMPANION(companion_entry)

extern "C" void companion_entry(int fd) {
    // TODO: read config from Zygisk companion channel
}
