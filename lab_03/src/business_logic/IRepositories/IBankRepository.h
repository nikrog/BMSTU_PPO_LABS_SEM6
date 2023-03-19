#ifndef PPO_IBANKREPOSITORY_H
#define PPO_IBANKREPOSITORY_H

#include "../models/ModelBank.h"
#include "CRUDRepository.h"

class IBankRepository : public CRUDRepository<Bank> {
public:
    virtual Bank getBankByID(int id);
    virtual Bank getBankByName(std::string name);
    virtual std::vector<Bank> getAllBanks();

    //virtual void updateBank(int id, std::string name, license_t license_num, std::string address, std::string email,
            //std::string phone, std::string website);
    //virtual void deleteBank(int id);
    virtual void addBank(BankInfo inf);
};


#endif //PPO_IBANKREPOSITORY_H
