#include <string>
#include <fstream>
#include <android/log.h>

#define LOG_TAG "OpenFG_Config"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

bool is_package_enabled(const std::string& pkg) {
    std::ifstream f("/data/adb/openfg_clone/packages.list");
    std::string line;
    while (std::getline(f, line)) {
        if (line == pkg) return true;
    }
    return false;
}
