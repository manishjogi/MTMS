#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int m_id;
    std::string m_name;
    std::string m_email;

public:
    User(int id, const std::string& name, const std::string& email);

    int getId() const;
    std::string getName() const;
    void setName(const std::string& name);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    void notify(const std::string& message) const;
};

#endif
