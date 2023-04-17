#include "AuthManager.h"

AuthManager::AuthManager(UserRules &controller)
{
    this->controller = UserRules(controller);
    this->getter = AuthGetter();
    this->printer = AuthPrinter();
    this->login = std::string();
    this->password = std::string();
}

AuthManager::AuthManager() {}

bool AuthManager::isAuthorized(std::string login)
{
    return this->controller.isUserExists(login);
}

Roles AuthManager::tryToAuthorize()
{
    Roles result = NON_AUTH;
    this->printer.print_login_entry();
    this->login = this->getter.getString();
    try
    {
        if (this->controller.isUserExists(login))
        {
            this->printer.print_password_entry();
            this->password = this->getter.getString();
            int tmpID = this->controller.getUserID(login);
            User tmpUser = this->controller.getUser(tmpID);
            if (tmpUser.getPassword() == this->password)
            {
                result = tmpUser.getUserRole();
                this->printer.print_success();
            }
            else
                throw IncorrectPassportException(__FILE__, typeid(*this).name(), __LINE__);
        }
        else
            throw LoginNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
    return result;
}

int AuthManager::getUserID(std::string login)
{
    int result = NONE;
    try
    {
        if (this->controller.isUserExists(login))
            result = this->controller.getUserID(login);
        else
            throw LoginNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
    return result;
}

std::string AuthManager::getLogin()
{
    return this->login;
}