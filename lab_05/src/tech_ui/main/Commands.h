#ifndef PPO_COMMANDS_H
#define PPO_COMMANDS_H

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

enum CMD_KEYS {
    EXIT,
    UN_AUTH,
    AUTH,
    VIEW_ALL_STUDENTS,
    VIEW_STUDENT,
    ADD_STUDENT,
    CHANGE_STUDENT,
    SETTLE_STUDENT,
    EVIC_STUDENT,
    VIEW_THINGS,
    VIEW_FREE_THINGS,
    ADD_THING,
    GIVE_THING,
    RETURN_THING,
    CHANGE_THING_LOC,
    VIEW_STUDENT_THINGS,
    VIEW_ROOMS,
    NOT_A_COMMAND
};

class CommandHandler {
private:
    bool check_is_number(std::string cmd);
public:
    CommandHandler() = default;
    ~CommandHandler() = default;
    CMD_KEYS handle(std::string cmd);
};


#endif //PPO_COMMANDS_H
