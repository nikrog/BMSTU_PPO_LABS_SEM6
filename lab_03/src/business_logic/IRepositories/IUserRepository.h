#ifndef PPO_IUSERREPOSITORY_H
#define PPO_IUSERREPOSITORY_H

#include "../models/ModelUser.h"
#include "CRUDRepository.h"
#include <iostream>
#include <string>


class IUserRepository : CRUDRepository<User> {
public:
    virtual int getUserID(std::string login);
    virtual User getUserByID(int id);
    virtual User getUserByLogin(std::string login);

    virtual void addUser(std::string login, std::string password, Roles permission);
    virtual void deleteUser(int id);
    virtual void updateUser(int id, std::string login, std::string password, Roles permission);
};

#endif //PPO_IUSERREPOSITORY_H
