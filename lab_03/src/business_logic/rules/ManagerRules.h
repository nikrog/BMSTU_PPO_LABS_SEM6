#ifndef PPO_MANAGERRULES_H
#define PPO_MANAGERRULES_H

#include "../models/ModelManager.h"
#include "../IRepositories/IManagerRepository.h"
#include "../exceptions/exceptions.h"

class ManagerRules {
private:
    IManagerRepository *repository;
public:
    ManagerRules(IManagerRepository &repository);
    ManagerRules();
    ~ManagerRules();

    Manager getManager(int id);
    std::vector<Manager> getManagerByBank(int bank_id);

    updateManagerBank(int id, int bank_id);
    deleteManager(int id);
    addManager(int user_id, int bank_id);
};
#endif //PPO_MANAGERRULES_H
