#include "ConfigManager.h"

std::string ConfigManager::getDB()
{
    std::string s, result = "unknown";
    std::ifstream out(CONF_FILE, std::fstream::in);
    if (out.is_open())
    {
        out >> s >> s >> result;
    }
    return result;
}

ConnectionParams ConfigManager::getParams()
{
    std::ifstream out(CONF_FILE, std::fstream::in);
    if (out.is_open())
    {
        std::string s, user, host, dbname, password, port;
        out >> s >> s >> s;
        out >> s >> s >> user;
        out >> s >> s >> host;
        out >> s >> s >> dbname;
        out >> s >> s >> password;
        out >> s >> s >> port;
        
        return ConnectionParams(user, host, dbname, password, std::atoi(port.c_str()));
    }
    else
        return ConnectionParams();
}

std::vector<int> ConfigManager::getBLparams()
{
    std::vector<int> params;
    std::ifstream out(CONF_FILE, std::fstream::in);
    if (out.is_open())
    {
        std::string s, len_passw, len_login;
        int n;
        out >> s >> s >> s;
        out >> s >> s >> s;
        out >> s >> s >> s;
        out >> s >> s >> s;
        out >> s >> s >> s;
        out >> s >> s >> s;
        out >> s >> s >> len_login;
        out >> s >> s >> len_passw;
        n = std::stoi(len_passw);
        params.push_back(n);
        n = std::stoi(len_login);
        params.push_back(n);
    }
    return params;
}