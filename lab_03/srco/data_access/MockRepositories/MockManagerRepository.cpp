#include "MockManagerRepository.h"

Manager MockManagerRepository::getManagerByID(int id)
{
    Manager tmpManager = Manager(id, 1, 1);
    return tmpManager;
}
Manager MockManagerRepository::getManagerByUID(int user_id)
{
    Manager tmpManager = Manager(1, user_id, 1);
    return tmpManager;
}
std::vector<Manager> MockManagerRepository::getManagerByBank(int bank_id)
{
    std::vector<Manager> managers = std::vector<Manager>();
    Manager tmpManager = Manager(1, 1, bank_id);
    managers.push_back(tmpManager);
    tmpManager = Manager(2, 2, bank_id);
    managers.push_back(tmpManager);
    return managers;
}
std::vector<Manager> MockManagerRepository::getAllManagers()
{
    std::vector<Manager> managers = std::vector<Manager>();
    Manager tmpManager = Manager(1, 1, 1);
    managers.push_back(tmpManager);
    tmpManager = Manager(2, 2, 2);
    managers.push_back(tmpManager);
    return managers;
}
void MockManagerRepository::updateEl(Manager manager_el)
{
    return;
}
void MockManagerRepository::deleteEl(int id)
{
    return;
}
int MockManagerRepository::addManager(int user_id, int bank_id)
{
    return 1;
}