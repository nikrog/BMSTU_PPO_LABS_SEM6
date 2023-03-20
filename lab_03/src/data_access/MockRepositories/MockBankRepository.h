#ifndef PPO_MOCKBANKREPOSITORY_H
#define PPO_MOCKBANKREPOSITORY_H

#include "../../business_logic/models/ModelBank.h"
#include "../../business_logic/IRepositories/IBankRepository.h"

class MockBankRepository : public IBankRepository{
public:
    Bank getBankByID(int id);
    Bank getBankByName(std::string name);
    std::vector<Bank> getAllBanks();
    int addBank(BankInfo inf);
    void deleteEl(int id);
    void updateEl(Bank bank_el);

};


#endif //PPO_MOCKBANKREPOSITORY_H
