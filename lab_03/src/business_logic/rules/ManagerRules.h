#ifndef PPO_MANAGERRULES_H
#define PPO_MANAGERRULES_H

#include "../models/ModelManager.h"
#include "../models/ModelBank.h"
#include "../models/ModelUser.h"
#include "../IRepositories/IManagerRepository.h"
#include "../IRepositories/IBankRepository.h"
#include "../IRepositories/IUserRepository.h"
#include "../exceptions/exceptions.h"

class ManagerRules {
private:
    IManagerRepository *repository;
    IBankRepository *bankRepository;
    IUserRepository *userRepository;
public:
    ManagerRules(IManagerRepository &repository, IBankRepository &bankRepository, IUserRepository &userRepository);
    ManagerRules();
    ~ManagerRules();

    Manager getManager(int id);
    std::vector<Manager> getManagerByBank(int bank_id);

    void updateManagerBank(int id, int bank_id);
    void deleteManager(int id);
    void addManager(int user_id, int bank_id);
    std::vector<Manager> getAllManagers();
};
#endif //PPO_MANAGERRULES_H
