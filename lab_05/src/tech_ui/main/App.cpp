#include "App.h"

App::App(AuthManager &authManager, ClientManager &clientManager, BankManager &bankManager,
        ManagersManager &managersManager, ProductManager &productManager, RequestManager &requestManager)
{
    this->printer = AppPrinter();
    this->cmd_handler = CommandHandler();
    this->app_state = AuthStates();
    this->id = NONE;
    this->authManager = authManager;
    this->clientManager = clientManager;
    this->bankManager = bankManager;
    this->managersManager = managersManager;
    this->productManager = productManager;
    this->requestManager = requestManager;
}

void App::menu()
{
    this->printer.print_menu();
    std::string cmd;
    std::cin >> cmd;
    CMD_KEYS key = this->getCommandKey(cmd);
    this->handleCommand(key);
}

CMD_KEYS App::getCommandKey(std::string cmd)
{
    return this->cmd_handler.handle(cmd);
}

void App::handleCommand(CMD_KEYS key)
{
    switch (key)
    {
    case EXIT:
        std::exit(EXIT);

    case UN_AUTH:
        if (!this->app_state.isUnAuth()) {
            this->app_state.toUnAuth();
        } else {
            this->printer.print_not_role();
        }
        break;

    case AUTH:
        if (this->app_state.isUnAuth())
        {
            Roles role = this->authManager.tryToAuthorize();
            switch (role) {
            case CLIENT:
            {
                this->app_state.toClientAuth();
                int userID = this->authManager.getUserID(this->authManager.getLogin());
                break;
            }
            case MANAGER:
                this->app_state.toManagerAuth();
                break;
            case ADMIN:
                this->app_state.toAdminAuth();
                break;
            default:
                break;
            }
        };
        break;

    case NOT_A_COMMAND:
        this->printer.print_not_a_command();
    }
}
