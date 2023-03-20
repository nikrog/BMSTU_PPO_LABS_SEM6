#include "IUserRepository.h"

int IUserRepository::getUserID(std::string login)
{return 1;}
User IUserRepository::getUserByID(int id)
{User usr = User();
return usr;}
User IUserRepository::getUserByLogin(std::string login)
{User usr = User();
return usr;}
int IUserRepository::addUser(UserInfo inf)
{return 1;}
void IUserRepository::updateEl(User usr)
{
    return;
}
void IUserRepository::deleteEl(int id)
{
    return;
}

std::vector<User> IUserRepository::getAllUsers()
{
    std::vector<User> users = std::vector<User>();
    return users;
}
//void IUserRepository::deleteUser(int id)
//{}
//void IUserRepository::updateUser(User el)
//{}