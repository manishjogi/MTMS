#include "Task.h"
#include <iostream>

Task::Task(int id, const std::string& name, const std::string& status, int priorty):
    m_id(id),
    m_name(name),
    m_status(status),
    m_priority(priorty){}

int Task::getId() const
{
    return m_id;
}

std::string Task::getname() const
{
    return m_name;
}

void Task::setName(const std::string &name)
{
    m_name = name;
}

std::string Task::getStatus() const
{
    return m_status;
}

void Task::setStatus(const std::string &status)
{
    m_status = status;
}

int Task::getPriority() const
{
    return m_priority;
}

void Task::setPriority(int priority)
{
    m_priority = priority;
}

void Task::addDependency(std::shared_ptr<Task> task)
{
    m_dependencies.push_back(task);
}

void Task::display() const
{
        std::cout << "Task ID: " << m_id << "\n"
                <<"Task Name:" << m_name << "\n"
                << "Status: " << m_status << "\n"
                << "Priority: " << m_priority << "\n"
                << "Dependencies: " << m_dependencies.size() << "\n";

}
