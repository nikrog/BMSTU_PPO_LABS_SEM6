#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgClientRepository.h"
#include "../../business_logic/rules/ClientRules.h"
#include "../../business_logic/models/ModelClient.h"
#include "../../business_logic/models/ModelUser.h"
#include "../../business_logic/models/ModelManager.h"
#include "../../data_access/PostgresRepositories/PgManagerRepository.h"
#include "../../data_access/PostgresRepositories/PgUserRepository.h"

TEST(TestPgClientRepo, TestAddandDeleteClient)
{
    ConnectionParams connectParams = ConnectionParams("postgres", "localhost", "postgres", "admin", 5435);
    PgClientRepository crep = PgClientRepository(connectParams);
    PgUserRepository urep = PgUserRepository(connectParams);
    PgManagerRepository mrep = PgManagerRepository(connectParams);
    ClientRules crules(crep, urep, mrep);

    int id = crules.addClient({.user_id=3, .name="c", .surname="c", .patronymic="c",
     .passport_num=99999, .birth_date=1977, .address="Street 11", .email="c@mail.ru", .phone="+79183456783"});
    Client tmpClient = crules.getClient(id);
    EXPECT_EQ(tmpClient.getID(), id);
    EXPECT_EQ(tmpClient.getUserID(), 3);
    EXPECT_EQ(tmpClient.getPassportNum(), 99999);
    crules.deleteClient(id);
    ASSERT_THROW(crules.getClient(id), ClientNotFoundException);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
