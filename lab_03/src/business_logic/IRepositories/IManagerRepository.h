#ifndef PPO_IMANAGERREPOSITORY_H
#define PPO_IMANAGERREPOSITORY_H

#include "../models/ModelManager.h"
#include "CRUDRepository.h"

class IManagerRepository : CRUDRepository<Manager> {
public:
    virtual Manager getManagerByID(int id);
    virtual std::vector<Manager> getManagerByBank(int bank_id);

    virtual updateManager(int id, int bank_id);
    virtual deleteManager(int id);
    virtual addManager(int user_id, int bank_id);
};


#endif //PPO_IMANAGERREPOSITORY_H
