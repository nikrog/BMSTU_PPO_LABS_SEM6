#include "IClientRepository.h"
Client IClientRepository::getClientByID(int id)
{}
Client IClientRepository::getClientByFIO(std::string name, std::string surname, std::string patronymic)
{}
void IClientRepository::addClient(int user_id, std::string name, std::string surname, std::string patronymic,
                       passport_t passport_num, date_t birth_date, std::string address,
                       std::string email, std::string phone)
{}
void IClientRepository::deleteClient(int id)
{}
void IClientRepository::updateClient(int id, int user_id, std::string name, std::string surname, std::string patronymic,
                          passport_t passport_num, date_t birth_date, std::string address,
                          std::string email, std::string phone)
{}