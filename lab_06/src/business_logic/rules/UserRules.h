#ifndef PPO_USERRULES_H
#define PPO_USERRULES_H

#include "../models/ModelUser.h"
#include "../IRepositories/IUserRepository.h"
#include "../exceptions/exceptions.h"

class UserRules {
private:
    IUserRepository *repository;
    int password_len;
    int login_len;
public:
    UserRules(IUserRepository &repository);
    UserRules(IUserRepository &repository, int password_len, int login_len);
    UserRules();
    ~UserRules();

    int getUserID(std::string login);
    User getUser(int id);
    std::vector<User> getAllUsers();
    int addUser(UserInfo inf);
    void deleteUser(int id);
    void updateUserLogin(int id, std::string new_login);
    void updateUserPassword(int id, std::string new_password);
    void updateUserPermission(int id, Roles new_permission);
    bool isUserExists(std::string login);
    Roles authUser(std::string login, std::string password);
    int getPasswLen();
};


#endif //PPO_USERRULES_H
