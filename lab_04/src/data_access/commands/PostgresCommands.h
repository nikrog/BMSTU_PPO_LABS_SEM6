#ifndef PPO_POSTGRESCOMMANDS_H
#define PPO_POSTGRESCOMMANDS_H

#include "../../business_logic/models/ModelUser.h"
#include "../../business_logic/models/ModelClient.h"
#include "../../business_logic/models/ModelBank.h"
#include "../../business_logic/models/ModelManager.h"
#include "../../business_logic/models/ModelProduct.h"
#include "../../business_logic/models/ModelRequest.h"

class PostgreSQLGetUserByID
{
public:
    PostgreSQLGetUserByID() = default;
    ~PostgreSQLGetUserByID() = default;
    std::string get_str(int id);
};

class PostgreSQLGetUserByLogin
{
public:
    PostgreSQLGetUserByLogin() = default;
    ~PostgreSQLGetUserByLogin() = default;
    std::string get_str(std::string login);
};

class PostgreSQLGetUserID
{
public:
    PostgreSQLGetUserID() = default;
    ~PostgreSQLGetUserID() = default;
    std::string get_str(std::string login);
};

class PostgreSQLAddUser
{
public:
    PostgreSQLAddUser() = default;
    ~PostgreSQLAddUser() = default;
    std::string get_str(UserInfo inf);
};

class PostgreSQLDeleteUser
{
public:
    PostgreSQLDeleteUser() = default;
    ~PostgreSQLDeleteUser() = default;
    std::string get_str(int id);
};

class PostgreSQLUpdateUser
{
public:
    PostgreSQLUpdateUser() = default;
    ~PostgreSQLUpdateUser() = default;
    std::string get_str(User user_el);
};

class PostgreSQLGetAllUsers
{
public:
    PostgreSQLGetAllUsers() = default;
    ~PostgreSQLGetAllUsers() = default;
    std::string get_str();
};



#endif //PPO_POSTGRESCOMMANDS_H