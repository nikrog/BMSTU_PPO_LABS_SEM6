#include "GuiBankManager.h"

GUIBankManager::GUIBankManager(BankRules &bController)
{
    this->bankController = bController;
}

GUIBankManager::GUIBankManager(){}

std::vector<Bank> GUIBankManager::printAllBanks()
{
    std::vector<Bank> banks = this->bankController.getAllBanks();
    return banks;
}