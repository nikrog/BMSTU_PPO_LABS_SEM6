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

class UserNotFoundException : public BaseException
{
public:
    UserNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = USER_NOT_FOUND_ERROR):
            BaseException(filename, classname, number_of_line, information) {};

};


class UserAddErrorException : public BaseException
{
public:
    UserAddErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = USER_ADD_ERROR):
            BaseException(filename, classname, number_of_line, information) {};

};

class UserDeleteErrorException : public BaseException
{
public:
    UserDeleteErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = USER_DELETE_ERROR):
            BaseException(filename, classname, number_of_line, information) {};

};

class UserUpdateErrorException : public BaseException
{
public:
    UserUpdateErrorException(std::string filename, std::string classname,
    int number_of_line,
            std::string information = USER_UPDATE_ERROR):
    BaseException(filename, classname, number_of_line, information) {};

};

class ManagerNotFoundException : public BaseException
{
public:
    ManagerNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = MANAGER_NOT_FOUND_ERROR):
            BaseException(filename, classname, number_of_line, information) {};

};

class ManagerAddErrorException : public BaseException
{
public:
    ManagerAddErrorException(std::string filename, std::string classname,
                             int number_of_line,
                             std::string information = MANAGER_ADD_ERROR):
            BaseException(filename, classname, number_of_line, information) {};

};

class ManagerUpdateErrorException : public BaseException
{
public:
    ManagerUpdateErrorException(std::string filename, std::string classname,
                             int number_of_line,
                             std::string information = MANAGER_UPDATE_ERROR):
            BaseException(filename, classname, number_of_line, information) {};

};

class ManagerDeleteErrorException : public BaseException
{
public:
    ManagerDeleteErrorException(std::string filename, std::string classname,
                             int number_of_line,
                             std::string information = MANAGER_DELETE_ERROR):
            BaseException(filename, classname, number_of_line, information) {};

};

#endif //PPO_EXCEPTIONS_H
