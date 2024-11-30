#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
#include <memory>

class Task {
    private:
        int m_id;
        std::string m_name;
        std::string m_status;
        int m_priority;
        std::vector<std::shared_ptr<Task>> m_dependencies;

    public:
        Task(int id, const std::string& name, const std::string& status, int priorty);

        int getId() const;
        
        std::string getname() const;
        void setName(const std::string& name);

        std::string getStatus() const;
        void setStatus(const std::string& status);

        int getPriority() const;
        void setPriority(int priority);

        void addDependency(std::shared_ptr<Task> task);
        void display() const;

};

#endif