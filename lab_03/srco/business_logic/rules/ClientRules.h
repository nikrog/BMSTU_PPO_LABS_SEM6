#ifndef PPO_CLIENTRULES_H
#define PPO_CLIENTRULES_H

#include "../models/ModelClient.h"
#include "../IRepositories/IClientRepository.h"
#include "../models/ModelUser.h"
#include "../IRepositories/IUserRepository.h"
#include "../models/ModelManager.h"
#include "../IRepositories/IManagerRepository.h"
#include "../exceptions/exceptions.h"

class ClientRules {
private:
    IClientRepository *repository;
    IUserRepository *userRepository;
    IManagerRepository *managerRepository;
public:
    ClientRules(IClientRepository &repository, IUserRepository &userRepository, IManagerRepository &managerRepository);
    ClientRules();
    ~ClientRules();

    Client getClient(int id);
    std::vector<Client> getClientByFIO(FIO name);
    void updateClient(Client client_el);
    void deleteClient(int id);
    void addClient(ClientInfo inf);
    std::vector<Client> getAllClients();
};


#endif //PPO_CLIENTRULES_H
