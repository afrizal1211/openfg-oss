#include "config.h"
#include <string>
#include <fstream>
#include <unistd.h>
#include <android/log.h>

#define LOG_TAG "OpenFG_Config"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

bool is_package_enabled(const std::string& pkg) {
    std::ifstream f("/data/adb/openfg_clone/packages.list");
    std::string line;
    while (std::getline(f, line)) {
        // Remove newlines
        if (!line.empty() && line.back() == '\n') line.pop_back();
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line == pkg) {
            LOGI("Package %s is enabled", pkg.c_str());
            return true;
        }
    }
    return false;
}

std::string read_app_config(const std::string& pkg, const std::string& key) {
    // Try to read from app's private files
    std::string path = "/data/user/0/" + pkg + "/files/" + key;
    std::ifstream f(path);
    if (f.is_open()) {
        std::string val;
        std::getline(f, val);
        return val;
    }
    return "";
}
