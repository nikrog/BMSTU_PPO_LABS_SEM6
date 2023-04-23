#include "App.h"

App::App(AuthManager &authManager, ClientManager &clientManager, BankManager &bankManager,
        ManagersManager &managersManager, ProductManager &productManager, RequestManager &requestManager)
{
    this->printer = AppPrinter();
    this->cmd_handler = CommandHandler();
    this->app_state = AuthStates();
    this->user_id = NONE;
    this->client_id = NONE;
    this->manager_id = NONE;
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
            this->printer.print_unauth_success();
            this->user_id = NONE;
            this->client_id = NONE;
            this->manager_id = NONE;
        }
        else {
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
                this->user_id = userID;
                this->client_id = this->clientManager.getClientByUserID(userID);
                //printf("%d %d", this->user_id, this->client_id);
                break;
            }
            case MANAGER:
            {
                this->app_state.toManagerAuth();
                int userID = this->authManager.getUserID(this->authManager.getLogin());
                this->user_id = userID;
                this->manager_id = this->managersManager.getManagerByUserID(userID);
                break;
            }
            case ADMIN:
            {
                this->app_state.toAdminAuth();
                int userID = this->authManager.getUserID(this->authManager.getLogin());
                this->user_id = userID;
                break;
            }
            default:
                break;
            }
        };
        break;

    case ADD_CLIENT:
        if ((this->app_state.isUnAuth()) || (this->app_state.isAdminAuth()))
        {
            this->clientManager.addClient();
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case ADD_MANAGER:
        if (this->app_state.isAdminAuth())
        {
            this->managersManager.addManager();
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case VIEW_CLIENT:
        if (this->app_state.isManagerAuth())
        {
            this->clientManager.viewClient();
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case VIEW_ALL_CLIENTS:
        if (this->app_state.isManagerAuth())
        {
            this->clientManager.viewAllClients();
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case ADD_PRODUCT:
        if ((this->app_state.isManagerAuth()) || (this->app_state.isAdminAuth()))
        {
            this->productManager.addProduct();
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case VIEW_ALL_PRODUCTS:
        this->productManager.viewAllProducts();
        break;
    case VIEW_ALL_REQUESTS:
        if ((this->app_state.isManagerAuth()) || (this->app_state.isAdminAuth()))
        {
            this->requestManager.viewAllRequests();
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case MAKE_REQUEST:
        if (this->app_state.isClientAuth())
        {
            this->requestManager.makeRequest(this->user_id, this->client_id);
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case VIEW_MY_REQUESTS:
        if (this->app_state.isClientAuth())
        {
            this->requestManager.viewMyRequests(this->client_id);
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case CONFIRM_REQUEST:
        if (this->app_state.isManagerAuth())
        {
            this->requestManager.confirmRequest(this->manager_id);
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case REJECT_REQUEST:
        if (this->app_state.isManagerAuth())
        {
            this->requestManager.rejectRequest(this->manager_id);
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case RATE_PRODUCT:
        if (this->app_state.isClientAuth())
        {
            this->requestManager.rateProduct(this->user_id);
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case VIEW_ALL_BANKS:
        this->bankManager.printAllBanks();
        break;
    case UPDATE_PRODUCT:
        if ((this->app_state.isManagerAuth()) || (this->app_state.isAdminAuth()))
        {
            this->productManager.changeProduct();
        }
        else {
            this->printer.print_not_role();
        }
        break;
    case NOT_A_COMMAND:
        this->printer.print_not_a_command();
    }
}
