#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgUserRepository.h"
#include "../../business_logic/rules/UserRules.h"
#include "../../business_logic/models/ModelUser.h"

TEST(TestPgUserRepo, TestGetUserIDByLogin)
{
    ConnectionParams connectParams = ConnectionParams("postgres", "localhost", "postgres", "admin", 5435);
    PgUserRepository rep = PgUserRepository(connectParams);
    UserRules urules(rep);

    int id = urules.getUserID("admin");
    ASSERT_EQ(id, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}