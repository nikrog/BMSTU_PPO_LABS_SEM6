#include "MockBankRepository.h"

Bank MockBankRepository::getBankByID(int id)
{
    Bank tmpBank = Bank(id, "VTB", 1234, "Street 9", "vtb@vtb.ru",
                        "+749567890555", "vtb.ru");
    return tmpBank;
}
Bank MockBankRepository::getBankByName(std::string name)
{
    Bank tmpBank = Bank(1, name, 1234, "Street 9", "vtb@vtb.ru",
                        "+749567890555", "vtb.ru");
    return tmpBank;
}
std::vector<Bank> MockBankRepository::getAllBanks()
{
    std::vector<Bank> banks = std::vector<Bank>();
    Bank tmpBank = Bank(1, "VTB", 1234, "Street 9", "vtb@vtb.ru",
                        "+749567890555", "vtb.ru");
    banks.push_back(tmpBank);
    tmpBank = Bank(2, "Sber", 1235, "Street 78", "sber@sber.ru",
                   "+749597895555", "sber.ru");
    banks.push_back(tmpBank);
    return banks;
}
void MockBankRepository::addBank(BankInfo inf)
{
    return;
}
void MockBankRepository::deleteEl(int id)
{
    return;
}
void MockBankRepository::updateEl(Bank bank_el)
{
    return;
}