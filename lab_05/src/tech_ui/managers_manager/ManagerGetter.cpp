#include "ManagerGetter.h"

bool ManagerGetter::check_is_number(std::string req)
{
    return !req.empty() && std::all_of(req.begin(), req.end(), ::isdigit);
}

int ManagerGetter::getInt()
{
    std::string str;
    int result = NONE;
    std::cin >> str;
    if (check_is_number(str))
        result = std::stoi(str);
    else
        throw InputIntErrorException(__FILE__, typeid(*this).name(), __LINE__);
    return result;
}