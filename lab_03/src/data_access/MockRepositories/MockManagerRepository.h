#ifndef PPO_MOCKMANAGERREPOSITORY_H
#define PPO_MOCKMANAGERREPOSITORY_H

#include "../../business_logic/models/ModelManager.h"
#include "../../business_logic/IRepositories/IManagerRepository.h"

class MockManagerRepository : public IManagerRepository{
public:
    Manager getManagerByID(int id);
    Manager getManagerByUID(int user_id);
    std::vector<Manager> getManagerByBank(int bank_id);
    std::vector<Manager> getAllManagers();
    void updateEl(Manager manager_el);
    void deleteEl(int id);
    void addManager(int user_id, int bank_id);
};


#endif //PPO_MOCKMANAGERREPOSITORY_H
