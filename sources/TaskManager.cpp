#include "TaskManager.h"
#include <iostream>

void TaskManager::addTask(const std::shared_ptr<Task>& task) {
    tasks.push_back(task);
    std::cout << "Task '" << task->getname() << "' added.\n";
}

void TaskManager::updateTaskStatus(int taskId, const std::string& newStatus) {
    for (const auto& task : tasks) {
        if (task->getId() == taskId) {
            task->setStatus(newStatus);
            std::cout << "Task '" << task->getname() << "' status updated to '" << newStatus << "'.\n";
            return;
        }
    }
    std::cout << "Task with ID " << taskId << " not found.\n";
}

void TaskManager::displayAllTasks() const {
    std::cout << "All Tasks:\n";
    for (const auto& task : tasks) {
        std::cout << "  - " << task->getname() << " (Status: " << task->getStatus() << ", Priority: " << task->getPriority() << ")\n";
    }
}
