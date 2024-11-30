#include "Project.h"
#include <iostream>

Project::Project(int id, const std::string& name, const std::string& description)
    : id(id), name(name), description(description) {}

void Project::addTask(const std::shared_ptr<Task>& task) {
    tasks.push_back(task);
    std::cout << "Task '" << task->getname() << "' added to project '" << name << "'\n";
}

void Project::addUser(const std::shared_ptr<User>& user) {
    users.push_back(user);
    std::cout << "User '" << user->getName() << "' added to project '" << name << "'\n";
}

void Project::displayDetails() const {
    std::cout << "Project: " << name << "\n"
              << "Description: " << description << "\n"
              << "Tasks:\n";
    for (const auto& task : tasks) {
        std::cout << "  - " << task->getname() << " (Priority: " << task->getPriority() << ")\n";
    }
    std::cout << "Users:\n";
    for (const auto& user : users) {
        std::cout << "  - " << user->getName() << " (" << user->getEmail() << ")\n";
    }
}
