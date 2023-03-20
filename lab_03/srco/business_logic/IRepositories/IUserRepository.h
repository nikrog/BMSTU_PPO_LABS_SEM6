#ifndef PPO_IUSERREPOSITORY_H
#define PPO_IUSERREPOSITORY_H

#include "../models/ModelUser.h"
#include "CRUDRepository.h"
#include <iostream>
#include <string>


class IUserRepository : public CRUDRepository<User> {
public:
    virtual int getUserID(std::string login);
    virtual User getUserByID(int id);
    virtual User getUserByLogin(std::string login);

    virtual int addUser(UserInfo inf);
    //virtual void deleteUser(int id);
    //virtual void updateUser(User el);
    virtual std::vector<User> getAllUsers();
};


#endif //PPO_IUSERREPOSITORY_H
