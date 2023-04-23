#ifndef PPO_IREQUESTREPOSITORY_H
#define PPO_IREQUESTREPOSITORY_H

#include "../models/ModelRequest.h"
#include "CRUDRepository.h"

class IRequestRepository : public CRUDRepository<Request>{
public:
    virtual Request getRequestByID(int id) = 0;
    virtual std::vector<Request> getRequestByState(State_t state) = 0;
    virtual std::vector<Request> getRequestByDate(date_t date) = 0;
    virtual std::vector<Request> getRequestByClient(int client_id) = 0;
    virtual std::vector<Request> getRequestByManager(int manager_id) = 0;
    virtual std::vector<Request> getRequestBySum(float min_sum, float max_sum) = 0;
    virtual std::vector<Request> getRequestByDuration(int min_time, int max_time) = 0;
    virtual std::vector<Request> getAllRequests() = 0;
    virtual int addRequest(RequestInfo inf) = 0;
};


#endif //PPO_IREQUESTREPOSITORY_H
