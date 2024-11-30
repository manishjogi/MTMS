#include "NotificationManager.h"
#include <iostream>

void NotificationManager::sendNotification(const User& user, const std::string& message) {
    notifications[user.getId()].push_back(message);
    std::cout << "Notification sent to " << user.getName() << ": " << message << "\n";
}

void NotificationManager::displayNotifications(const User& user) const {
    auto it = notifications.find(user.getId());
    if (it != notifications.end()) {
        std::cout << "Notifications for " << user.getName() << ":\n";
        for (const auto& notification : it->second) {
            std::cout << "  - " << notification << "\n";
        }
    } else {
        std::cout << "No notifications for " << user.getName() << "\n";
    }
}
