#ifndef PPO_MODELREQUEST_H
#define PPO_MODELREQUEST_H

#include "constants.h"
#include <iostream>
#include <string>

enum State_t {
    OPENED = 0,
    APPROVED = 1,
    REJECTED = 2,
    CLOSED = 3
};

class Request {
private:
    int id;
    int client_id;
    int bank_id;
    int manager_id;
    float sum;
    int duration;
    date_t date;
    State_t state;

public:
    Request(int id, int client_id, int bank_id, int manager_id, float sum, int duration, date_t date, State_t state);
    Request();
    ~Request();

    int getID();
    int getClientID();
    int getBankID();
    int getManagerID();
    float getSum();
    int getDuration();
    date_t getDate();
    State_t getState();


    void setSum(float sum);
    void setDuration(int duration);
    void setDate(date_t date);
    void setState(State_t state);
    void setManagerID(int manager_id);
};


#endif //PPO_MODELREQUEST_H