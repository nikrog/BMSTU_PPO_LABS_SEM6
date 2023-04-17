#include "App.h"

int main()
{
    ConnectionParams connectParams = ConnectionParams("postgres", "localhost", "postgres", "admin", 5435);

    PgUserRepository userRepo = PgUserRepository(connectParams);
    PgBankRepository bankRepo = PgBankRepository(connectParams);
    PgManagerRepository managerRepo = PgManagerRepository(connectParams);
    PgClientRepository clientRepo = PgClientRepository(connectParams);
    PgProductRepository productRepo = PgProductRepository(connectParams);
    PgRequestRepository requestRepo = PgRequestRepository(connectParams);

    UserRules urules(userRepo);
    BankRules brules(bankRepo);
    ManagerRules mrules(managerRepo, bankRepo, userRepo, clientRepo);
    ClientRules crules(clientRepo, userRepo, managerRepo);
    ProductRules prules(productRepo, bankRepo);
    RequestRules rrules(requestRepo, clientRepo, managerRepo, productRepo, userRepo);

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