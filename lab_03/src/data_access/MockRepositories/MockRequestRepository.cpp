#include "MockRequestRepository.h"

Request MockRequestRepository::getRequestByID(int id)
{
    Request tmpRequest = Request(id,1,1,1,10000, 365, 10, OPENED);
    return tmpRequest;
}

std::vector<Request> MockRequestRepository::getRequestByState(State_t state)
{
    std::vector<Request> requests = std::vector<Request>();
    Request tmpRequest = Request(1,1,1,1,10000, 365, 10, state);
    requests.push_back(tmpRequest);
    tmpRequest = Request(2,1,2,1,10000, 365, 10, state);
    requests.push_back(tmpRequest);
    return requests;
}
std::vector<Request> MockRequestRepository::getRequestByDate(date_t date)
{
    std::vector<Request> requests = std::vector<Request>();
    Request tmpRequest = Request(1,1,1,1,10000, 365, date, OPENED);
    requests.push_back(tmpRequest);
    tmpRequest = Request(2,1,1,1,10000, 365, date, APPROVED);
    requests.push_back(tmpRequest);
    return requests;
}
std::vector<Request> MockRequestRepository::getRequestByClient(int client_id)
{
    std::vector<Request> requests = std::vector<Request>();
    Request tmpRequest = Request(1,client_id,1,1,10000, 365, 10, OPENED);
    requests.push_back(tmpRequest);
    tmpRequest = Request(2,client_id,2,1,10000, 365, 10,APPROVED);
    requests.push_back(tmpRequest);
    return requests;
}
std::vector<Request> MockRequestRepository::getRequestByManager(int manager_id)
{
    std::vector<Request> requests = std::vector<Request>();
    Request tmpRequest = Request(1,1,1,manager_id,10000, 365, 10, REJECTED);
    requests.push_back(tmpRequest);
    tmpRequest = Request(2,1,2, manager_id,10000, 365, 10, APPROVED);
    requests.push_back(tmpRequest);
    return requests;
}
std::vector<Request> MockRequestRepository::getRequestBySum(float min_sum, float max_sum)
{
    std::vector<Request> requests = std::vector<Request>();
    Request tmpRequest = Request(1,1,1,1,min_sum, 365, 10, APPROVED);
    requests.push_back(tmpRequest);
    tmpRequest = Request(2,1,2,1,max_sum, 365, 10, CLOSED);
    requests.push_back(tmpRequest);
    return requests;
}
std::vector<Request> MockRequestRepository::getRequestByDuration(int min_time, int max_time)
{
    std::vector<Request> requests = std::vector<Request>();
    Request tmpRequest = Request(1,1,1,1,10000, min_time, 10, OPENED);
    requests.push_back(tmpRequest);
    tmpRequest = Request(2,1,2,1,10000, max_time, 10, APPROVED);
    requests.push_back(tmpRequest);
    return requests;
}
std::vector<Request> MockRequestRepository::getAllRequests()
{
    std::vector<Request> requests = std::vector<Request>();
    Request tmpRequest = Request(1,1,1,1,10000, 365, 10, OPENED);
    requests.push_back(tmpRequest);
    tmpRequest = Request(2,1,2,1,10000, 365, 10, APPROVED);
    requests.push_back(tmpRequest);
    return requests;
}
void MockRequestRepository::addRequest(RequestInfo inf)
{
    return;
}
void MockRequestRepository::deleteEl(int id)
{
    return;
}
void MockRequestRepository::updateEl(Request req_el)
{
    return;
}