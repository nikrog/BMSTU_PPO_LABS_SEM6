#include "App.h"

int main()
{
    ConnectionParams connectParams = ConnectionParams("postgres", "localhost", "postgres", "admin", 5435);

    PgUserRepository userRepo = PgUserRepository(connectParams);
    UserRules urules(userRepo);

    PgClientRepository clientRepo = PgClientRepository(connectParams);
    ClientRules crules(clientRepo);

    PgProductRepository productRepo = PgProductRepository(connectParams);
    ProductRules prules(productRepo);

    PgManagerRepository managerRepo = PgManagerRepository(connectParams);
    ManagerRules mrules(managerRepo);

    PgBankRepository bankRepo = PgBankRepository(connectParams);
    BankRules brules(bankRepo);

    PgRequestRepository requestRepo = PgRequestRepository(connectParams);
    RequestRules rrules(requestRepo);

    AuthManager authManager(urules);
    ClientManager clManager(crules, urules);
    ManagersManager manManager(mrules, urules);
    BankManager bankManager(brules);
    ProductManager prodManager(prules);
    RequestManager reqManager(rrules);

    App app(authManager, clManager, bankManager, manManager, prodManager, reqManager);

    for (;;)
        app.menu();
}