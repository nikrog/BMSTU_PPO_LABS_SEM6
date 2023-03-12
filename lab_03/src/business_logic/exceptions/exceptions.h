#ifndef PPO_EXCEPTIONS_H
#define PPO_EXCEPTIONS_H

#include <exception>
#include <iostream>
#include "../models/constants.h"

class BaseException: public std::exception
{
public:
    BaseException(std::string fileName, std::string className,
                  int currentLine,
                  std::string information);

    virtual const char *what() const noexcept override;

protected:
    std::string info;
};

#endif //PPO_EXCEPTIONS_H
