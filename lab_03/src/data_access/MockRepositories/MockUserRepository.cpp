#include "MockUserRepository.h"

int MockUserRepository::getUserID(std::string login)
{
    return 1;
}

User MockUserRepository::getUserByID(int id)
{
    User tmpUser = User(id, "login", "1111", CLIENT);
    return tmpUser;
}

User MockUserRepository::getUserByLogin(std::string login)
{
    User tmpUser = User(1, login, "1111", CLIENT);
    return tmpUser;
}

int MockUserRepository::addUser(UserInfo inf)
{
    return 1;
}
void MockUserRepository::deleteEl(int id)
{
    return;
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