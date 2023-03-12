#include "IUserRepository.h"

int IUserRepository::getUserID(std::string login)
{}
User IUserRepository::getUserByID(int id)
{}
User IUserRepository::getUserByLogin(int id)
{}
void IUserRepository::addUser(std::string login, std::string password, Roles permission)
{}
void IUserRepository::deleteUser(int id)
{}
void IUserRepository::updateUser(int id, std::string login, std::string password, Roles permission)
{}