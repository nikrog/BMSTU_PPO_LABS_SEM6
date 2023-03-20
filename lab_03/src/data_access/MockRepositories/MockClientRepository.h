#ifndef PPO_MOCKCLIENTREPOSITORY_H
#define PPO_MOCKCLIENTREPOSITORY_H

#include "../../business_logic/models/ModelClient.h"
#include "../../business_logic/IRepositories/IClientRepository.h"

class MockClientRepository : public IClientRepository{
public:
    Client getClientByID(int id);
    std::vector<Client> getClientByFIO(FIO name);
    std::vector<Client> getAllClients();
    int addClient(ClientInfo inf);
    void deleteEl(int id);
    void updateEl(Client client_el);
};


#endif //PPO_MOCKCLIENTREPOSITORY_H
