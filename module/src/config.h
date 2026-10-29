#ifndef CONFIG_H
#define CONFIG_H
#include <string>
bool is_package_enabled(const std::string& pkg);
std::string read_app_config(const std::string& pkg, const std::string& key);
#endif
