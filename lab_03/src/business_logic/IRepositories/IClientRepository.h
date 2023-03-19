#ifndef PPO_ICLIENTREPOSITORY_H
#define PPO_ICLIENTREPOSITORY_H

#include "../models/ModelClient.h"
#include "CRUDRepository.h"

class IClientRepository : public CRUDRepository<Client> {
public:
    virtual Client getClientByID(int id);
    virtual std::vector<Client> getClientByFIO(FIO name);
    virtual std::vector<Client> getAllClients();

    virtual void addClient(ClientInfo inf);
    //virtual void deleteClient(int id);
    //virtual void updateClient(int id, int user_id, std::string name, std::string surname, std::string patronymic,
                              //passport_t passport_num, date_t birth_date, std::string address,
                              //std::string email, std::string phone);
};


#endif //PPO_ICLIENTREPOSITORY_H
