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
{}
User UserRules::getUser(int id)
{}
void UserRules::addUser(std::string login, std::string password, Roles permission)
{}
bool UserRules::isUserExists(std::string login)
{}