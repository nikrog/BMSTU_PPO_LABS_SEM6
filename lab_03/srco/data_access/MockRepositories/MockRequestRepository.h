#ifndef PPO_MOCKREQUESTREPOSITORY_H
#define PPO_MOCKREQUESTREPOSITORY_H

#include "../../business_logic/models/ModelRequest.h"
#include "../../business_logic/IRepositories/IRequestRepository.h"

class MockRequestRepository : public IRequestRepository{
public:
    Request getRequestByID(int id);
    std::vector<Request> getRequestByState(State_t state);
    std::vector<Request> getRequestByDate(date_t date);
    std::vector<Request> getRequestByClient(int client_id);
    std::vector<Request> getRequestByManager(int manager_id);
    std::vector<Request> getRequestBySum(float min_sum, float max_sum);
    std::vector<Request> getRequestByDuration(int min_time, int max_time);
    std::vector<Request> getAllRequests();
    int addRequest(RequestInfo inf);
    void deleteEl(int id);
    void updateEl(Request req_el);
};


#endif //PPO_MOCKREQUESTREPOSITORY_H
