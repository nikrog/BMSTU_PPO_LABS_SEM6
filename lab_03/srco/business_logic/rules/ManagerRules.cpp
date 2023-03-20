#include "ManagerRules.h"

ManagerRules::ManagerRules(IManagerRepository &repository, IBankRepository &bankRepository,
                           IUserRepository &userRepository, IClientRepository &clientRepository) {
    this->repository = repository;
    this->bankRepository = bankRepository;
    this->userRepository = userRepository;
    this->clientRepository = clientRepository;
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
    User tmpUser = this->userRepository->getUserByID(user_id);
    if (tmpUser.getID() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    Bank tmpBank = this->bankRepository->getBankByID(bank_id);
    if (tmpBank.getID() == NONE)
        throw BankNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Manager> managers = this->repository->getAllManagers();
    for (size_t i = 0; i < managers.size(); i++)
        if (managers[i].getUserID() == user_id)
            throw ManagerAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Client> clients = this->clientRepository->getAllClients();
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getUserID() == user_id)
            throw ManagerAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    int id = this->repository->addManager(user_id, bank_id);
    Manager tmpManager = this->repository->getManagerByID(id);
    if (tmpManager.getID() == NONE)
        throw ManagerAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

void ManagerRules::deleteManager(int id) {
    Manager tmpManager = this->repository->getManagerByID(id);
    if (tmpManager.getID() > NONE)
    {
        try {
            this->repository->deleteEl(id);
            Manager testManager = this->repository->getManagerByID(id);
            if (testManager.getID() != NONE)
                throw ManagerDeleteErrorException(__FILE__, typeid(*this).name(), __LINE__);
        }
        catch (ManagerNotFoundException) {}
    }
    else
        throw ManagerNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}

void ManagerRules::updateManagerBank(int id, int bank_id) {
    Manager tmpManager = this->repository->getManagerByID(id);
    if (tmpManager.getID() == NONE)
        throw ManagerNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    Bank tmpBank = this->bankRepository->getBankByID(bank_id);
    if (tmpBank.getID() == NONE)
        throw BankNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    tmpManager.setBankID(bank_id);
    this->repository->updateEl(tmpManager);
    tmpManager = this->repository->getManagerByID(id);
    if (tmpManager.getID() == NONE)
        throw ManagerNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpManager.getBankID() != bank_id)
        throw ManagerUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

std::vector<Manager> ManagerRules::getAllManagers() {
    std::vector<Manager> managers = this->repository->getAllManagers();
    return managers;
}