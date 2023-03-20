#include <gtest/gtest.h>
#include "f.h"
#include "../../business_logic/models/ModelUser.h"
#include "../../business_logic/rules/UserRules.h"
#include "../../data_access/MockRepositories/MockUserRepository.h"

/*TEST(f, positive)
{
    ASSERT_EQ(1, f());
}*/

TEST(TestUserRules, TestAddUserPositive)
{
    std::vector<User> users;
    users.push_back(User(1, "abc", "11112", CLIENT));
    MockUserRepository userRepository(users);
    UserRules urules(userRepository);
    urules.addUser({.login="789", .password="11111", .permission=CLIENT});
    User usr = urules.getUser(2);
    EXPECT_EQ(usr.getID(), 2);
    EXPECT_EQ(usr.getLogin(), "789");
    EXPECT_EQ(usr.getPassword(), "11111");
    EXPECT_EQ(usr.getUserRole(), CLIENT);
}

TEST(TestUserRules, TestAddUserIncorrectPassword)
{
std::vector<User> users;
users.push_back(User(1, "abc", "11112", CLIENT));
MockUserRepository userRepository(users);
UserRules urules(userRepository);
ASSERT_THROW(urules.addUser({.login="789", .password="111", .permission=CLIENT}), UserAddErrorException);
}

TEST(TestUserRules, TestAddUserIncorrectLogin)
{
std::vector<User> users;
users.push_back(User(1, "abc", "11112", CLIENT));
MockUserRepository userRepository(users);
UserRules urules(userRepository);
ASSERT_THROW(urules.addUser({.login="", .password="111", .permission=CLIENT}), UserAddErrorException);
}

TEST(TestUserRules, TestAddUserIncorrectLogin2)
{
std::vector<User> users;
users.push_back(User(1, "abc", "11112", CLIENT));
MockUserRepository userRepository(users);
UserRules urules(userRepository);
ASSERT_THROW(urules.addUser({.login="abc", .password="111", .permission=CLIENT}), UserAddErrorException);
}

TEST(TestUserRules, TestDeleteUserPositive)
{
std::vector<User> users;
users.push_back(User(1, "abc", "11112", CLIENT));
MockUserRepository userRepository(users);
UserRules urules(userRepository);
urules.deleteUser(1);
ASSERT_THROW(urules.getUser(1), UserNotFoundException);
}

TEST(TestUserRules, TestDeleteUserNegative)
{
std::vector<User> users;
users.push_back(User(1, "abc", "11112", CLIENT));
MockUserRepository userRepository(users);
UserRules urules(userRepository);
ASSERT_THROW(urules.getUser(2), UserNotFoundException);
}

TEST(TestUserRules, TestGetAllUsers)
{
std::vector<User> users;
MockUserRepository userRepository(users);
UserRules urules(userRepository);
users = urules.getAllUsers();
EXPECT_EQ(users.size(), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}