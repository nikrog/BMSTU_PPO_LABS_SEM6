#include <gtest/gtest.h>
#include "../../business_logic/models/ModelManager.h"
#include "../../business_logic/rules/ManagerRules.h"
#include "../../data_access/MockRepositories/MockManagerRepository.h"

TEST(TestUserRules, TestAddUserPositive)
{
    std::vector<Manager> managers;
    managers.push_back(Manager(1, 1, 1));
    MockManagerRepository managerRepository(managers);
    ManagerRules mrules();
    //urules.addUser({.login="789", .password="11111", .permission=CLIENT});
    //User usr = urules.getUser(2);
    //EXPECT_EQ(usr.getID(), 2);
    //EXPECT_EQ(usr.getLogin(), "789");
    //EXPECT_EQ(usr.getPassword(), "11111");
    //EXPECT_EQ(usr.getUserRole(), CLIENT);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}