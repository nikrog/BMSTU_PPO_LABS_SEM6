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
