#ifndef PPO_GUIAUTHMANAGER_H
#define PPO_GUIAUTHMANAGER_H

#include "../../business_logic/rules/UserRules.h"

class GUIAuthManager {
private:
    std::string login;
    std::string password;
    UserRules controller;
public:
    GUIAuthManager(UserRules &controller);
    GUIAuthManager();
    ~GUIAuthManager() = default;
    bool isAuthorized(std::string login);
    Roles tryToAuthorize(std::string login, std::string password);
    int getUserID(std::string login);
    std::string getLogin();
};


#endif //PPO_GUIAUTHMANAGER_H
