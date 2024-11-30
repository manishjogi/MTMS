#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include "Task.h"
#include <queue>
#include <functional>
#include <mutex>
#include <thread>

class TaskScheduler {
private:
    std::priority_queue<std::shared_ptr<Task>, std::vector<std::shared_ptr<Task>>, 
                        std::function<bool(const std::shared_ptr<Task>&, const std::shared_ptr<Task>&)>> taskQueue;
    std::mutex queueMutex;
    bool running;

    void processTasks();

public:
    TaskScheduler();
    ~TaskScheduler();
    void addTask(const std::shared_ptr<Task>& task);
    void start();
    void stop();
};

#endif
