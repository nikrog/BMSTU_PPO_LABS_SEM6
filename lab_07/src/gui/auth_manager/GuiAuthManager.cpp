#include "GuiAuthManager.h"

GUIAuthManager::GUIAuthManager(UserRules &controller)
{
    this->controller = UserRules(controller);
    this->login = std::string();
    this->password = std::string();
}

GUIAuthManager::GUIAuthManager() {}

bool GUIAuthManager::isAuthorized(std::string login)
{
    return this->controller.isUserExists(login);
}

Roles GUIAuthManager::tryToAuthorize(std::string login, std::string password)
{
    Roles result = NON_AUTH;
    result = this->controller.authUser(login, password);
    if (result == NON_AUTH)
    { 
        throw IncorrectPasswordOrLoginException(__FILE__, typeid(*this).name(), __LINE__);
    }
    return result;
}

int GUIAuthManager::getUserID(std::string login)
{
    int result = NONE;
    if (this->controller.isUserExists(login))
        result = this->controller.getUserID(login);
    else
        throw LoginNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    return result;
}

std::string GUIAuthManager::getLogin()
{
    return this->login;
}
