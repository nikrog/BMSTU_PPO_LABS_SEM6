#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgManagerRepository.h"
#include "../../business_logic/rules/ManagerRules.h"
#include "../../business_logic/models/ModelManager.h"
#include "../../data_access/PostgresRepositories/PgBankRepository.h"
#include "../../data_access/PostgresRepositories/PgClientRepository.h"
#include "../../data_access/PostgresRepositories/PgUserRepository.h"

TEST(TestPgManagerRepo, TestAddandDeleteManager)
{
    ConnectionParams connectParams = ConnectionParams("postgres", "localhost", "postgres", "admin", 5435);
    PgManagerRepository mrep = PgManagerRepository(connectParams);
    PgBankRepository brep = PgBankRepository(connectParams);
    PgClientRepository crep = PgClientRepository(connectParams);
    PgUserRepository urep = PgUserRepository(connectParams);
    
    ManagerRules mrules(mrep, brep, urep, crep);

    int id = mrules.addManager(2, 1);
    Manager tmpManager = mrules.getManager(id);
    EXPECT_EQ(tmpManager.getID(), id);
    EXPECT_EQ(tmpManager.getUserID(), 2);
    EXPECT_EQ(tmpManager.getBankID(), 1);
    mrules.deleteManager(id);
    ASSERT_THROW(mrules.getManager(id), ManagerNotFoundException);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
