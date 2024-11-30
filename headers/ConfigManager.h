#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <unordered_map>

class ConfigManager {
private:
    std::unordered_map<std::string, std::string> config;

public:
    void setConfig(const std::string& key, const std::string& value);
    std::string getConfig(const std::string& key) const;
    void displayConfig() const;
};

#endif
