#include "ManagerRules.h"

ManagerRules::ManagerRules(IManagerRepository &repository) {
    this->repository = repository;
}

ManagerRules::ManagerRules()
{}

ManagerRules::~ManagerRules()
{}

Manager ManagerRules::getManager(int id) {
    Manager tmpManager = this->repository->getManagerByID();

    User tmpUser = this->repository->getUserByID(id);
    if (tmpManager.getID() == NONE)
        throw ManagerNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpManager;
}

std::vector<Manager> ManagerRules::getManagerByBank(int bank_id)
{
    std::vector<Manager> managers = this->repository->getManagerByBank(bank_id);
    return managers;
}

void ManagerRules::addManager(int user_id, int bank_id) {
    if ((user_id <= NONE) || (bank_id <= NONE))
        throw ManagerAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Manager> managers = this->repository->getAllManagers();
    for (size_t i = 0; i < managers.size(); i++)
        if (managers[i].getUserID() == user_id)
            throw ManagerAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->addManager(user_id, bank_id);
    std::vector<Manager> managers = this->repository->getAllManagers();
    for (size_t i = 0; i < managers.size(); i++)
        if (managers[i].getUserID() == user_id)
            break;
    if (i == managers.size())
        throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    /*int id = this->repository->getManagerID(user_id);
    if (id == NONE)
        throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);*/
}

void ManagerRules::deleteManager(int id) {
    Manager tmpManager = this->repository->getManagerByID(id);
    if (tmpManager.getID() > NONE)
    {
        try {
            this->repository->deleteManager(id);
            Manager testManager = this->repository->getManagerByID(id);
            if (testManager.getID() != NONE)
                throw ManagerDeleteErrorException(__FILE__, typeid(*this).name(), __LINE__);
        }
        catch (ManagerNotFoundException) {}
    }

    if (id != NONE)
        throw ManagerNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}

void ManagerRules::updateManagerBank(int id, int bank_id) {
    //TODO: code
    /*User tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (new_login.length() < MIN_LOGIN_LEN)
        throw UserUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<User> users = this->repository->getAllUsers();
    for (size_t i = 0; i < users.size(); i++)
        if (users[i].getLogin() == new_login)
            throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->updateUser(id, new_login, tmpUser.getPassword(), tmpUser.getUserRole());
    tmpUser = this->repository->getUserByID(id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpUser.getLogin() != new_login)
        throw UserUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);*/
}
