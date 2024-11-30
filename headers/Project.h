#ifndef PROJECT_H
#define PROJECT_H

#include "Task.h"
#include "User.h"
#include <vector>
#include <string>
#include <memory>

class Project {
private:
    int id;
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Task>> tasks;
    std::vector<std::shared_ptr<User>> users;

public:
    Project(int id, const std::string& name, const std::string& description);

    void addTask(const std::shared_ptr<Task>& task);
    void addUser(const std::shared_ptr<User>& user);

    void displayDetails() const;
};

#endif
