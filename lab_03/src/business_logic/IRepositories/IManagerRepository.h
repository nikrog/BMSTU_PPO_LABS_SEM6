#ifndef PPO_IMANAGERREPOSITORY_H
#define PPO_IMANAGERREPOSITORY_H

#include "../models/ModelManager.h"
#include "CRUDRepository.h"

class IManagerRepository : public CRUDRepository<Manager> {
public:
    virtual Manager getManagerByID(int id);
    virtual Manager getManagerByUID(int user_id);
    virtual std::vector<Manager> getManagerByBank(int bank_id);
    virtual std::vector<Manager> getAllManagers();

    //virtual updateManager(int id, int bank_id);
    //virtual deleteManager(int id);
    virtual addManager(int user_id, int bank_id);
};


#endif //PPO_IMANAGERREPOSITORY_H
