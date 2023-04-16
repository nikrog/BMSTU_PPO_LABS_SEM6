#include "RequestManager.h"

RequestManager::RequestManager(RequestRules &rController)
{
    this->requestController = rController;
    this->printer = RequestPrinter();
    this->getter = RequestGetter();
}

RequestManager::RequestManager(){}

void RequestManager::viewAllRequests()
{
    std::vector<Request> requests = this->requestController.getAllRequests();
    for (size_t i = 0; i < requests.size(); i++)
    {
        this->printer.printRequest(requests[i]);
    }
}

void RequestManager::makeRequest(int client_id)
{
    this->printer.printInputProductID();
    int prod_id = this->getter.getInt();

    this->printer.printInputSum();
    float sum = this->getter.getFloat();

    this->printer.printInputDuration();
    int duration = this->getter.getInt();

    try
    {
        this->productController.addProduct({.client_id=client_id, .product_id=product_id, .manager_id=NONE, 
        .sum=sym, .duration=duration, .date=DEF_TIME, .state=OPENED});
        this->printer.printAddSuccess();
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void RequestManager::changeRequest()
{
    this->printer.printInputID();
    int tmpID = this->getter.getInt();

    try
    {
        Request tmpRequest = this->requestController.getRequest(tmpID);
        if (tmpRequest.getID() != NONE)
        {

            this->printer.printInputSum();
            float sum = this->getter.getFloat();
            if (sum > 0)
            {
                tmpRequest.setSum(sum);
            }
            
            this->printer.printInputDuration();
            int duration = this->getter.getInt();
            if (duration > 0)
            {
                tmpRequest.setDuration(duration);
            }

            this->requestController.updateRequest(tmpRequest);
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void RequestManager::rejectRequest(int manager_id)
{
    this->printer.printInputID();
    int tmpID = this->getter.getInt();
    try
    {
        Request tmpRequest = this->requestController.getRequest(tmpID);
        if (tmpRequest.getID() != NONE)
        {

            this->requestController.rejectRequest(tmpID, manager_id);
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void RequestManager::confirmRequest(int manager_id)
{
    this->printer.printInputID();
    int tmpID = this->getter.getInt();
    try
    {
        Request tmpRequest = this->requestController.getRequest(tmpID);
        if (tmpRequest.getID() != NONE)
        {

            this->requestController.confirmRequest(tmpID, manager_id);
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}