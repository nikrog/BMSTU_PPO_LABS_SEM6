#include "IRequestRepository.h"

Request IRequestRepository::getRequestByID(int id)
{}
std::vector<Request> IRequestRepository::getRequestByState(State_t state)
{}
std::vector<Request> IRequestRepository::getRequestByDate(date_t date)
{}
std::vector<Request> IRequestRepository::getRequestByClient(int client_id)
{}
std::vector<Request> IRequestRepository::getRequestByManager(int manager_id)
{}
std::vector<Request> IRequestRepository::getRequestBySum(float min_sum, float max_sum)
{}
std::vector<Request> IRequestRepository::getRequestByDuration(int min_time, int max_time)
{}

void IRequestRepository::updateRequest(int id, int client_id, int bank_id, int manager_id,
                           float sum, int duration, date_t date, State_t state)
{}
void IRequestRepository::deleteRequest(int id)
{}
void IRequestRepository::addRequest(int client_id, int bank_id, int manager_id, float sum,
                        int duration, date_t date, State_t stateg)
{}