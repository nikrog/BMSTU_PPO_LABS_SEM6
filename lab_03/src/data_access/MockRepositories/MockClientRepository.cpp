#include "MockClientRepository.h"

Client MockClientRepository::getClientByID(int id)
{
    Client tmpClient = Client(id, 1, "abc", "abc", "abc", 123456,
                              1975, "Komarovo", "t@mail.ru", "+7903617890");
    return tmpClient;
}
std::vector<Client> MockClientRepository::getClientByFIO(FIO name)
{
    std::vector<Client> clients = std::vector<Client>();
    Client tmpClient = Client(1, 1, name.name, name.surname, name.patronymic, 123456,
                              1975, "Komarovo", "t@mail.ru", "+7903617890");
    clients.push_back(tmpClient);
    return clients;
}
std::vector<Client> MockClientRepository::getAllClients()
{
    std::vector<Client> clients = std::vector<Client>();
    Client tmpClient = Client(1, 1, "abc", "abc", "abc", 123456,
                              1975, "Komarovo", "t@mail.ru", "+7903617890");
    clients.push_back(tmpClient);
    tmpClient = Client(2, 2, "abv", "abv", "abv", 123458,
                              1979, "Komarovo", "t2@mail.ru", "+7903617870");
    clients.push_back(tmpClient);
    return clients;
}
void MockClientRepository::addClient(ClientInfo inf)
{
    return;
}
void MockClientRepository::deleteEl(int id)
{
    return;
}
void MockClientRepository::updateEl(Client client_el)
{
    return;
}