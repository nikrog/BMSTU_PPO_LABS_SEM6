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

std::string GUIBankManager::getBankNameByID(int id)
{
    Bank bank = this->bankController.getBank(id);
    return bank.getName();
}

int GUIBankManager::getBankIDByName(std::string name)
{
    int id;
    try
    {
        Bank bank = this->bankController.getBankByName(name);
        id = bank.getID();
    }
    catch (const std::exception &e)
    {
        id = NONE;
    }
    return id;
}

void GUIBankManager::deleteBank(int bank_id)
{
    this->bankController.deleteBank(bank_id);
}
