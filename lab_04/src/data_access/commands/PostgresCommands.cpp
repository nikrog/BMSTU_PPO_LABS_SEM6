#include "PostgresCommands.h"

std::string PostgreSQLGetUserByID::get_str(int id)
{
    return "SELECT * FROM BA.users WHERE user_id = " + std::to_string(id) + ";";
}

std::string PostgreSQLGetUserByLogin::get_str(std::string login)
{
    return "SELECT * FROM BA.users WHERE login = '" + login + "';";
}

std::string PostgreSQLGetUserID::get_str(std::string login)
{
    return "SELECT user_id FROM BA.users WHERE login = '" + login + "';";
}

std::string PostgreSQLAddUser::get_str(UserInfo inf)
{
    return "INSERT INTO BA.users(login, password, permission) VALUES ('" + inf.login + "', '" + inf.password + "', " +
    std::to_string(inf.permission) + ");";
}

std::string PostgreSQLDeleteUser::get_str(int id)
{
    return "DELETE FROM BA.users WHERE user_id = " + std::to_string(id) + ";";
}

std::string PostgreSQLUpdateUser::get_str(User user_el)
{
    return "UPDATE BA.users SET login = '" + user_el.getLogin() + "', password = '" + user_el.getPassword() + "', permission = " +
    std::to_string(user_el.getUserRole()) + "WHERE user_id = " + std::to_string(user_el.getID()) + ";";
}

std::string PostgreSQLGetAllUsers::get_str()
{
    return "SELECT * FROM BA.users";
}