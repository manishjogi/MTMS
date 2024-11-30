#include "Task.h"
#include "User.h"
#include "NotificationManager.h"
#include "TaskManager.h"
#include "ConfigManager.h"
#include "TaskScheduler.h"
#include "Project.h"
#include <memory>
#include <iostream>

int main() {
    // Step 1: Create Users
    auto user1 = std::make_shared<User>(1, "Alice", "alice@example.com");
    auto user2 = std::make_shared<User>(2, "Bob", "bob@example.com");

    // Step 2: Create Tasks
    auto task1 = std::make_shared<Task>(1, "Design system architecture", "Pending", 5);
    auto task2 = std::make_shared<Task>(2, "Write documentation", "In Progress", 3);
    auto task3 = std::make_shared<Task>(3, "Implement feature X", "Pending", 4);

    // // Step 3: Test Project Management
    // Project project(1, "New Software Development", "End-to-end software project");
    // project.addTask(task1);
    // project.addTask(task2);
    // project.addUser(user1);
    // project.addUser(user2);
    // project.displayDetails();

    // Step 4: Test Notification Manager
    NotificationManager notificationManager;
    notificationManager.sendNotification(*user1, "Task 'Design system architecture' has been updated.");
    notificationManager.sendNotification(*user2, "Task 'Write documentation' has been completed.");
    notificationManager.displayNotifications(*user1);
    notificationManager.displayNotifications(*user2);

    // Step 5: Test Task Manager
    TaskManager taskManager;
    taskManager.addTask(task1);
    taskManager.addTask(task2);
    taskManager.addTask(task3);
    taskManager.displayAllTasks();

    taskManager.updateTaskStatus(1, "Completed");
    taskManager.displayAllTasks();

    // // Step 6: Test Config Manager
    // ConfigManager configManager;
    // configManager.setConfig("max_tasks", "10");
    // configManager.setConfig("notification_enabled", "true");
    // std::cout << "Config - Max Tasks: " << configManager.getConfig("max_tasks") << "\n";
    // configManager.displayConfig();

    // Step 7: Test Task Scheduler
    TaskScheduler taskScheduler;
    taskScheduler.addTask(task1);
    taskScheduler.addTask(task2);
    taskScheduler.addTask(task3);

    // std::cout << "Starting Task Scheduler...\n";
    // taskScheduler.start();

    // // Simulate a delay to observe scheduler execution
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    // taskScheduler.stop();

    // std::cout << "Task Scheduler stopped.\n";

    return 0;
}
