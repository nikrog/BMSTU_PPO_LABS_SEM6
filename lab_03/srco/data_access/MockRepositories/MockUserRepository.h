#ifndef PPO_MOCKUSERREPOSITORY_H
#define PPO_MOCKUSERREPOSITORY_H


#include "../../business_logic/models/ModelUser.h"
#include "../../business_logic/IRepositories/IUserRepository.h"

class MockUserRepository : public IUserRepository{
public:
    int getUserID(std::string login);
    User getUserByID(int id);
    User getUserByLogin(std::string login);

    int addUser(UserInfo inf);
    void deleteEl(int id);
    void updateEl(User user_el);
    std::vector<User> getAllUsers();

};


#endif //PPO_MOCKUSERREPOSITORY_H
