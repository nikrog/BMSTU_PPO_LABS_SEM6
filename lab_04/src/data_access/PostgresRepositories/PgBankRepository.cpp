#include "PgBankRepository.h"

Bank PgBankRepository::getBankByID(int id)
{
    Bank resultBank;
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetUserByID().get_str(id);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            if (result.size() > 0)
            {
                //TODO:
                resultBank = User(id, result[0][1].as<std::string>(), result[0][2].as<std::string>(),
                                  Roles(result[0][3].as<int>()));
            }
            else
                resultBank = Bank();
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultBank;   
}
Bank PgBankRepository::getBankByName(std::string name)
{}
std::vector<Bank> PgBankRepository::getAllBanks()
{}
int PgBankRepository::addBank(BankInfo inf)
{}
void PgBankRepository::deleteEl(int id) 
{}
void PgBankRepository::updateEl(Bank bank_el) 
{}