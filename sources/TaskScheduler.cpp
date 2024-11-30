#include "TaskScheduler.h"
#include <iostream>
#include <chrono>

TaskScheduler::TaskScheduler()
    : taskQueue([](const std::shared_ptr<Task>& a, const std::shared_ptr<Task>& b) {
          return a->getPriority() < b->getPriority();
      }),
      running(false) {}

TaskScheduler::~TaskScheduler() {
    stop();
}

void TaskScheduler::addTask(const std::shared_ptr<Task>& task) {
    std::lock_guard<std::mutex> lock(queueMutex);
    taskQueue.push(task);
    std::cout << "Task '" << task->getname() << "' added to the scheduler.\n";
}

void TaskScheduler::start() {
    running = true;
    std::thread(&TaskScheduler::processTasks, this).detach();
}

void TaskScheduler::stop() {
    running = false;
}

void TaskScheduler::processTasks() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate processing delay
        std::lock_guard<std::mutex> lock(queueMutex);
        if (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();
            std::cout << "Processing task: " << task->getname() << "\n";
        }
    }
}
