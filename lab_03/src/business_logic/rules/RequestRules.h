#ifndef PPO_REQUESTRULES_H
#define PPO_REQUESTRULES_H

#include "../models/ModelProduct.h"
#include "../IRepositories/IProductRepository.h"
#include "../models/ModelUser.h"
#include "../IRepositories/IUserRepository.h"
#include "../models/ModelRequest.h"
#include "../IRepositories/IRequestRepository.h"
#include "../models/ModelClient.h"
#include "../IRepositories/IClientRepository.h"
#include "../models/ModelManager.h"
#include "../IRepositories/IManagerRepository.h"
#include "../exceptions/exceptions.h"

class RequestRules {
private:
    IRequestRepository *repository;
    IClientRepository *clientRepository;
    IManagerRepository *managerRepository;
    IProductRepository *productRepository;
    IUserRepository *userRepository;
public:
    RequestRules(IRequestRepository &repository, IClientRepository &clientRepository,
                 IManagerRepository &managerRepository, IProductRepository &productRepository,
                 IUserRepository &userRepository);
    RequestRules();
    ~RequestRules();

    Request getRequest(int id);
    std::vector<Request> getRequestByClient(int client_id);
    std::vector<Request> getRequestByDate(date_t date);
    std::vector<Request> getRequestByState(State_t s);
    std::vector<Request> getRequestByManager(int manager_id);
    std::vector<Request> getRequestByDuration(int min_time, int max_time);
    std::vector<Request> getRequestBySum(float min_sum, float max_sum);
    void makeRequest(int user_id, RequestInfo inf);
    void confirmRequest(int req_id, int manager_id);
    void rejectRequest(int req_id, int manager_id);

    void updateRequest(Request req_el);
    void deleteRequest(int id);
    void addRequest(RequestInfo inf);
    std::vector<Request> getAllRequests();
};


#endif //PPO_REQUESTRULES_H
