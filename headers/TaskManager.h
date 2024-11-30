#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Task.h"
#include <vector>
#include <memory>

class TaskManager {
private:
    std::vector<std::shared_ptr<Task>> tasks;

public:
    void addTask(const std::shared_ptr<Task>& task);
    void updateTaskStatus(int taskId, const std::string& newStatus);
    void displayAllTasks() const;
};

#endif
