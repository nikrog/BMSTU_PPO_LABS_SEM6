#include "ModelUser.h"

User::User(int id, std::string login, std::string password, Roles permission)
{
    this->id = id;
    this->login = login;
    this->password = password;
    this->permission = permission;
}

User::User()
{
    this->id = NONE;
    this->login = EMPTY;
    this->password = EMPTY;
    this->privelegeLevel = NON_AUTH;
}

User::~User()
{}

int User::getID()
{
    return this->id;
}

std::string User::getLogin()
{
    return this->login;
}

std::string User::getPassword()
{
    return this->password;
}

Roles User::getUserRole()
{
    return this->permission;
}

