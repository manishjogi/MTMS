#include "ConfigManager.h"
#include <iostream>

void ConfigManager::setConfig(const std::string& key, const std::string& value) {
    config[key] = value;
    std::cout << "Configuration set: " << key << " = " << value << "\n";
}

std::string ConfigManager::getConfig(const std::string& key) const {
    auto it = config.find(key);
    if (it != config.end()) {
        return it->second;
    }
    return "Key not found";
}

void ConfigManager::displayConfig() const {
    std::cout << "Configurations:\n";
    for (const auto& entry : config) {
        std::cout << "  " << entry.first << " = " << entry.second << "\n";
    }
}
