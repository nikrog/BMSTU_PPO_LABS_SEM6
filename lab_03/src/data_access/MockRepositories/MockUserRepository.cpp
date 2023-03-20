#include "MockUserRepository.h"

MockUserRepository::MockUserRepository(std::vector<User> users)
{
    this->users = users;
}

MockUserRepository::~MockUserRepository()
{}

int MockUserRepository::getUserID(std::string login)
{
    return 1;
}

User MockUserRepository::getUserByID(int id)
{
    for (User tmpUser : this->users)
    {
        if (tmpUser.getID() == id)
            return tmpUser;
    }
    return User();
}

User MockUserRepository::getUserByLogin(std::string login)
{
    for (User tmpUser : this->users)
    {
        if (tmpUser.getLogin() == login)
            return tmpUser;
    }
    return User();
}

int MockUserRepository::addUser(UserInfo inf)
{
    int N = this->users.size();
    User tmpUser = User(N + 1, inf.login, inf.password, inf.permission);
    this->users.push_back(tmpUser);
    return N + 1;
}
void MockUserRepository::deleteEl(int id)
{
    std::vector<User> new_users;
    for (User tmpUser : this->users)
    {
        if (tmpUser.getID() != id)
            new_users.push_back(tmpUser);
    }
    this->users = new_users;
}
void MockUserRepository::updateEl(User user_el)
{
    return;
}
std::vector<User> MockUserRepository::getAllUsers()
{
    std::vector<User> users = std::vector<User>();
    User tmpUser = User(1, "login", "1111", CLIENT);
    users.push_back(tmpUser);
    tmpUser = User(2, "admin", "admin", ADMIN);
    users.push_back(tmpUser);
    return users;
}