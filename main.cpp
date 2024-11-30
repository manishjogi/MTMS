#include "Task.h"
#include "User.h"
#include <memory>

int main() {
    // Create a Task
    auto task1 = std::make_shared<Task>(1, "Code Review", "Pending", 5);
    auto task2 = std::make_shared<Task>(2, "Write Documentation", "In Progress", 3);

    task1->addDependency(task2);

    // Display Task Details
    task1->display();
    task2->display();

    // Create a User
    User user1(1, "Alice", "alice@example.com");
    user1.notify("Your task is due soon!");

    return 0;
}
