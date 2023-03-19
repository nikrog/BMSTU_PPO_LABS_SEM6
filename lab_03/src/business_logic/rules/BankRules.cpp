#include "BankRules.h"

BankRules::BankRules(IManagerRepository &repository)
{
    this->repository = repository;
}
BankRules::BankRules()
{}
BankRules::~BankRules()
{}

Bank BankRules::getBank(int id)
{
    Bank tmpBank = this->repository->getBankByID(id);
    if (tmpBank.getID() == NONE)
        throw BankNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpBank;
}

Bank BankRules::getBankByName(std::string name)
{
    Bank tmpBank = this->repository->getBankByName(name);
    if (tmpBank.getID() == NONE)
        throw BankNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpBank;
}

void BankRules::updateBank(Bank bank_el)
{
    if ((bank_el.getName().length() < 1) || (bank_el.getLicenseNum() < 1))
        throw BankUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->updateEl(bank_el);
}

void BankRules::deleteBank(int id)
{
    Bank tmpBank = this->repository->getBankByID(id);
    if (tmpBank.getID() > NONE)
    {
        try {
            this->repository->deleteEl(id);
            Bank testBank = this->repository->getBankByID(id);
            if (testBank.getID() != NONE)
                throw BankDeleteErrorException(__FILE__, typeid(*this).name(), __LINE__);
        }
        catch (BankNotFoundException) {}
    }
    else
        throw BankNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}

void BankRules::addBank(BankInfo inf)
{
    if ((inf.name.length() < 1) || (inf.license_num < 1))
        throw BankAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->addBank(inf);
    int id = this->repository->getBankByName(inf.name);
    if (id == NONE)
        throw BankAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

std::vector<Bank> BankRules::getAllBanks()
{
    std::vector<Bank> banks = this->repository->getAllBanks();
    return banks;
}
