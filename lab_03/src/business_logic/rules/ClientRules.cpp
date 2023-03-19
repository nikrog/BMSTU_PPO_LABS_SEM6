#include "ClientRules.h"

ClientRules::ClientRules(IClientRepository &repository, IUserRepository &userRepository)
{
    this->repository = repository;
    this->userRepository = userRepository;
}
ClientRules::ClientRules()
{}
ClientRules::~ClientRules()
{}

Client ClientRules::getClient(int id)
{
    Client tmpClient = this->repository->getClientByID(id);
    if (tmpClient.getID() == NONE)
        throw ClientNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpClient;
}

std::vector<Client> ClientRules::getClientByFIO(FIO name)
{
    std::vector<Client> clients = this->repository->getClientByFIO(name);
    return clients;
}

void ClientRules::updateClient(Client client_el)
{
    if ((client_el.getName().length() < 1) || (client_el.getSurname().length() < 1) ||
    (client_el.getPatronymic().length() < 1) || (client_el.getPassportNum() < 1))
        throw ClientUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->updateEl(client_el);
}

void ClientRules::deleteClient(int id)
{
    Client tmpClient = this->repository->getClientByID(id);
    if (tmpClient.getID() > NONE)
    {
        try {
            this->repository->deleteEl(id);
            Client testClient = this->repository->getClientByID(id);
            if (testClient.getID() != NONE)
                throw ClientDeleteErrorException(__FILE__, typeid(*this).name(), __LINE__);
        }
        catch (ClientNotFoundException) {}
    }
    else
        throw ClientNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}

void ClientRules::addClient(ClientInfo inf)
{
    if ((inf.name.length() < 1) || (inf.surname.length() < 1) ||
        (inf.patronymic.length() < 1) || (inf.passport_num < 1))
        throw ClientAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    User tmpUser = this->userRepository->getUserByID(inf.user_id);
    if (tmpUser.getID() == NONE)
        throw ClientAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Client> clients = this->repository->getAllClients();
    for (size_t i = 0; i < clients.size(); i++)
        if ((clients[i].getUserID() == inf.user_id) || (clients[i].getPassportNum() == inf.passport_num))
            throw ClientAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->addClient(inf);
    clients = this->repository->getAllClients();
    int id = NONE;
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getPassportNum() == inf.passport_num)
            id = clients[i].getID();
    if (id == NONE)
        throw ClientAddErrorException(__FILE__, typeid(*this).name(), __LINE__);

}
std::vector<Client> ClientRules::getAllClients()
{
    std::vector<Client> clients = this->repository->getAllClients();
    return clients;
}
