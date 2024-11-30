#ifndef NOTIFICATION_MANAGER_H
#define NOTIFICATION_MANAGER_H

#include "User.h"
#include <string>
#include <unordered_map>
#include <vector>

class NotificationManager {
private:
    std::unordered_map<int, std::vector<std::string>> notifications;

public:
    void sendNotification(const User& user, const std::string& message);
    void displayNotifications(const User& user) const;
};

#endif
