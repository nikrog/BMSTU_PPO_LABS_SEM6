#ifndef PPO_USERRULES_H
#define PPO_USERRULES_H

#include "../models/ModelUser.h"
#include "../IRepositories/IUserRepository.h"
#include "../exceptions/exceptions.h"

class UserRules {
private:
    IUserRepository *repository;
public:
    UserRules(IUserRepository &repository);
    UserRules();
    ~UserRules();

    int getUserID(std::string login);
    User getUser(int id);
    void addUser(std::string login, std::string password, Roles permission);
    bool isUserExists(std::string login);
};


#endif //PPO_USERRULES_H
