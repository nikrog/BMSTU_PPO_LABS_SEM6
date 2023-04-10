#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgRequestRepository.h"
#include "../../business_logic/rules/RequestRules.h"
#include "../../business_logic/models/ModelRequest.h"
#include "../../data_access/PostgresRepositories/PgClientRepository.h"
#include "../../data_access/PostgresRepositories/PgManagerRepository.h"
#include "../../data_access/PostgresRepositories/PgProductRepository.h"
#include "../../data_access/PostgresRepositories/PgUserRepository.h"

TEST(TestPgRequestRepo, TestAddandDeleteRequest)
{
    ConnectionParams connectParams = ConnectionParams("postgres", "localhost", "postgres", "admin", 5435);
    PgRequestRepository rrep = PgRequestRepository(connectParams);
    PgManagerRepository mrep = PgManagerRepository(connectParams);
    PgProductRepository prep = PgProductRepository(connectParams);
    PgClientRepository crep = PgClientRepository(connectParams);
    PgUserRepository urep = PgUserRepository(connectParams);
    
    RequestRules rrules(rrep, crep, mrep, prep, urep);

    int id = rrules.makeRequest(4, {.client_id=1, .product_id=1, .manager_id=NONE, .sum=60000, .duration=365, .date=2023, .state=OPENED});
    Request tmpRequest = rrules.getRequest(id);
    EXPECT_EQ(tmpRequest.getID(), id);
    EXPECT_EQ(tmpRequest.getClientID(), 1);
    EXPECT_EQ(tmpRequest.getProductID(), 1);
    rrules.deleteRequest(id);
    ASSERT_THROW(rrules.getRequest(id), RequestNotFoundException);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

