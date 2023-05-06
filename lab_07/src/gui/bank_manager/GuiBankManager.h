#ifndef PPO_GUIBANKMANAGER_H
#define PPO_GUIBANKMANAGER_H

#include "../../business_logic/rules/BankRules.h"

class GUIBankManager {
private:
    BankRules bankController;
public:
    GUIBankManager(BankRules &bController);
    GUIBankManager();
    ~GUIBankManager() = default;
    std::vector<Bank> printAllBanks();
};


#endif //PPO_GUIBANKMANAGER_H
