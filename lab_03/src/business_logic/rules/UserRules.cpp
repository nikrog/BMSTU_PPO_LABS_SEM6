#include "UserRules.h"

UserRules::UserRules(IUserRepository &repository)
{
    this->repository = repository;
}

UserRules::UserRules()
{}

UserRules::~UserRules()
{}

int UserRules::getUserID(std::string login)
{
    int id = this->repository->getUserID(login);
    if (id == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return id;
}

User UserRules::getUser(int id)
{
    User tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpUser;
}

void UserRules::addUser(std::string login, std::string password, Roles permission)
{
    if ((permission > ADMIN) || (permission < CLIENT))
        throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if (login.length() < MIN_LOGIN_LEN or password.length() < MIN_PASSWORD_LEN)
        throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<User> users = this->repository->getAllUsers();
    for (size_t i = 0; i < users.size(); i++)
        if (users[i].getLogin() == login)
            throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->addUser(login, password, permission);
    int id = this->repository->getUserID(login);
    if (id == NONE)
        throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

void UserRules::deleteUser(int id) {
    User tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() > NONE)
    {
        try {
            this->repository->deleteUser(id);
            User testUser = this->repository->getUserByID(id);
            if (testUser.getID() != NONE)
                throw UserDeleteErrorException(__FILE__, typeid(*this).name(), __LINE__);
        }
        catch (UserNotFoundException) {}
    }

    if (id != NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}

void UserRules::updateUserLogin(int id, std::string new_login)
{
    User tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (new_login.length() < MIN_LOGIN_LEN)
        throw UserUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<User> users = this->repository->getAllUsers();
    for (size_t i = 0; i < users.size(); i++)
        if (users[i].getLogin() == new_login)
            throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->updateUser(id, new_login, tmpUser.getPassword(), tmpUser.getUserRole());
    tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpUser.getLogin() != new_login)
        throw UserUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

void UserRules::updateUserPassword(int id, std::string new_password)
{
    User tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (new_password.length() < MIN_PASSWORD_LEN)
        throw UserUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->updateUser(id, tmpUser.getLogin(), new_password, tmpUser.getUserRole());
    tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpUser.getPassword() != new_password)
        throw UserUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

void UserRules::updateUserPermission(int id, Roles new_permission) {
    User tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if ((new_permission > ADMIN) || (new_permission < CLIENT))
        throw UserUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->updateUser(id, tmpUser.getLogin(), tmpUser.getPassword(), new_permission);
    tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpUser.getUserRole() != new_permission)
        throw UserUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
}


bool UserRules::isUserExists(std::string login)
{
    return (this->repository->getUserID(login) > NONE);
}

std::vector<User> UserRules::getAllUsers()
{
    std::vector<User> users = this->repository->getAllUsers();
    return users;
}