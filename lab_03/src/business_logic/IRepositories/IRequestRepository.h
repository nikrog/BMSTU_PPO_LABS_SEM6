#ifndef PPO_IREQUESTREPOSITORY_H
#define PPO_IREQUESTREPOSITORY_H

#include "../models/ModelRequest.h"
#include "CRUDRepository.h"

class IRequestRepository : CRUDRepository<Request>{
public:
    virtual Request getRequestByID(int id);
    virtual std::vector<Request> getRequestByState(State_t state);
    virtual std::vector<Request> getRequestByDate(date_t date);
    virtual std::vector<Request> getRequestByClient(int client_id);
    virtual std::vector<Request> getRequestByManager(int manager_id);
    virtual std::vector<Request> getRequestBySum(float min_sum, float max_sum);
    virtual std::vector<Request> getRequestByDuration(int min_time, int max_time);

    virtual void updateRequest(int id, int client_id, int bank_id, int manager_id,
                               float sum, int duration, date_t date, State_t state);
    virtual void deleteRequest(int id);
    virtual void addRequest(int client_id, int bank_id, int manager_id, float sum,
                            int duration, date_t date, State_t stateg);
};


#endif //PPO_IREQUESTREPOSITORY_H
