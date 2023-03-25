#include "RequestRules.h"

RequestRules::RequestRules(IRequestRepository &repository, IClientRepository &clientRepository,
                           IManagerRepository &managerRepository, IProductRepository &productRepository,
                           IUserRepository &userRepository)
{
    this->repository = &repository;
    this->clientRepository = &clientRepository;
    this->managerRepository = &managerRepository;
    this->productRepository = &productRepository;
    this->userRepository = &userRepository;
}

RequestRules::RequestRules()
{}

RequestRules::~RequestRules()
{}

Request RequestRules::getRequest(int id) {
    Request tmpRequest = this->repository->getRequestByID(id);
    if (tmpRequest.getID() == NONE)
        throw RequestNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpRequest;
}

std::vector<Request> RequestRules::getRequestByClient(int client_id)
{
    std::vector<Client> clients = this->clientRepository->getAllClients();
    int id = NONE;
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getID() == client_id)
            id = clients[i].getID();
    if (id == NONE)
        throw RequestGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Request> requests = this->repository->getRequestByClient(client_id);
    return requests;

}

std::vector<Request> RequestRules::getRequestByDate(date_t date)
{
    std::vector<Request> requests = this->repository->getRequestByDate(date);
    return requests;
}

std::vector<Request> RequestRules::getRequestByState(State_t s)
{
    std::vector<Request> requests = this->repository->getRequestByState(s);
    return requests;
}

std::vector<Request> RequestRules::getRequestByManager(int manager_id)
{
    if (manager_id != NONE)
    {
        std::vector<Manager> managers = this->managerRepository->getAllManagers();
        int id = NONE;
        for (size_t i = 0; i < managers.size(); i++)
            if (managers[i].getID() == manager_id)
                id = managers[i].getID();
        if (id == NONE)
            throw RequestGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    }
    std::vector<Request> requests = this->repository->getRequestByManager(manager_id);
    return requests;
}

std::vector<Request> RequestRules::getRequestByDuration(int min_time, int max_time)
{
    if ((min_time < MIN_TIME) || (max_time < MIN_TIME) || (min_time > max_time))
        throw RequestGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Request> requests = this->repository->getRequestByDuration(min_time, max_time);
    return requests;
}

std::vector<Request> RequestRules::getRequestBySum(float min_sum, float max_sum)
{
    if ((min_sum < MIN_SUM) || (max_sum < MIN_SUM) || (min_sum > max_sum))
        throw RequestGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Request> requests = this->repository->getRequestBySum(min_sum, max_sum);
    return requests;
}

int RequestRules::makeRequest(int user_id, RequestInfo inf)
{
    User tmpUser = this->userRepository->getUserByID(user_id);
    if (tmpUser.getUserRole() != CLIENT)
        throw RequestMakeErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if (inf.manager_id != NONE)
        throw RequestMakeErrorException(__FILE__, typeid(*this).name(), __LINE__);
    // check fullness of client account
    std::vector<Client> clients = this->clientRepository->getAllClients();
    int id = NONE;
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getUserID() == user_id)
            id = clients[i].getID();
    if (id == NONE)
        throw RequestMakeErrorException(__FILE__, typeid(*this).name(), __LINE__);
    Product tmpProduct = this->productRepository->getProductByID(inf.product_id);
    if (tmpProduct.getID() == NONE)
        throw ProductNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if ((tmpProduct.getMinSum() > inf.sum) || (tmpProduct.getMaxSum() < inf.sum) || (tmpProduct.getMinTime() > inf.duration) 
    || (tmpProduct.getMaxTime() < inf.duration))
        throw RequestMakeErrorException(__FILE__, typeid(*this).name(), __LINE__);
    id = RequestRules::addRequest(inf);
    return id;
}
void RequestRules::rateProduct(int req_id, int user_id, int rating)
{
    Request tmpRequest = this->repository->getRequestByID(req_id);
    if (tmpRequest.getID() == NONE)
        throw RequestNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Client> clients = this->clientRepository->getAllClients();
    int id = NONE;
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getUserID() == user_id)
            id = clients[i].getID();
    if (id == NONE)
        throw ProductRateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpRequest.getClientID() != id)
        throw ProductRateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if ((tmpRequest.getState() != CLOSED) && (tmpRequest.getState() != APPROVED))
        throw ProductRateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    Product tmpProduct = this->productRepository->getProductByID(tmpRequest.getProductID());
    if (tmpProduct.getID() == NONE)
        throw ProductRateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    tmpProduct.incSumRating(rating);
    tmpProduct.incCountRating();
    this->productRepository->updateEl(tmpProduct);
}

void RequestRules::confirmRequest(int req_id, int manager_id)
{
    Request tmpRequest = this->repository->getRequestByID(req_id);
    if (tmpRequest.getID() == NONE)
        throw RequestNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    Manager tmpManager = this->managerRepository->getManagerByID(manager_id);
    if (tmpManager.getID() == NONE)
        throw RequestConfirmErrorException(__FILE__, typeid(*this).name(), __LINE__);
    Product tmpProduct = this->productRepository->getProductByID(tmpRequest.getProductID());
    if (tmpProduct.getID() == NONE)
        throw RequestConfirmErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpProduct.getBankID() != tmpManager.getBankID())
        throw RequestConfirmErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpRequest.getState() != OPENED)
        throw RequestConfirmErrorException(__FILE__, typeid(*this).name(), __LINE__);
    tmpRequest.setManagerID(manager_id);
    tmpRequest.setState(APPROVED);
    this->repository->updateEl(tmpRequest);
}

void RequestRules::rejectRequest(int req_id, int manager_id)
{
    Request tmpRequest = this->repository->getRequestByID(req_id);
    if (tmpRequest.getID() == NONE)
        throw RequestNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    Manager tmpManager = this->managerRepository->getManagerByID(manager_id);
    if (tmpManager.getID() == NONE)
        throw RequestRejectErrorException(__FILE__, typeid(*this).name(), __LINE__);
    Product tmpProduct = this->productRepository->getProductByID(tmpRequest.getProductID());
    if (tmpProduct.getID() == NONE)
        throw RequestRejectErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpProduct.getBankID() != tmpManager.getBankID())
        throw RequestRejectErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpRequest.getState() != OPENED)
        throw RequestRejectErrorException(__FILE__, typeid(*this).name(), __LINE__);
    tmpRequest.setManagerID(manager_id);
    tmpRequest.setState(REJECTED);
    this->repository->updateEl(tmpRequest);
}

void RequestRules::updateRequest(Request req_el)
{
    if ((req_el.getDuration() < MIN_TIME) || (req_el.getSum() < MIN_SUM) || (req_el.getState() < OPENED) ||
            (req_el.getState() > CLOSED))
        throw RequestUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Client> clients = this->clientRepository->getAllClients();
    int id = NONE;
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getID() == req_el.getClientID())
            id = clients[i].getID();
    if (id == NONE)
        throw RequestUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    if (req_el.getManagerID() != NONE)
    {
        id = NONE;
        std::vector<Manager> managers = this->managerRepository->getAllManagers();
        for (size_t i = 0; i < managers.size(); i++)
            if (managers[i].getID() == req_el.getManagerID())
                id = managers[i].getID();
        if (id == NONE)
            throw RequestUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    }
    this->repository->updateEl(req_el);
}

void RequestRules::deleteRequest(int id)
{
    Request tmpRequest = this->repository->getRequestByID(id);
    if (tmpRequest.getID() > NONE)
    {
        try {
            this->repository->deleteEl(id);
            Request testRequest = this->repository->getRequestByID(id);
            if (testRequest.getID() != NONE)
                throw RequestDeleteErrorException(__FILE__, typeid(*this).name(), __LINE__);
        }
        catch (RequestNotFoundException) {}
    }
    else
        throw RequestNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}

int RequestRules::addRequest(RequestInfo inf)
{
    if ((inf.duration < MIN_TIME) || (inf.sum < MIN_SUM) || (inf.state != OPENED))
        throw RequestAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Client> clients = this->clientRepository->getAllClients();
    int id = NONE;
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getID() == inf.client_id)
            id = clients[i].getID();
    if (id == NONE)
        throw RequestAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    id = this->repository->addRequest(inf);
    Request tmpRequest = this->repository->getRequestByID(id);
    if (tmpRequest.getID() == NONE)
        throw RequestAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    return id;
}

std::vector<Request> RequestRules::getAllRequests()
{
    std::vector<Request> requests = this->repository->getAllRequests();
    return requests;
}