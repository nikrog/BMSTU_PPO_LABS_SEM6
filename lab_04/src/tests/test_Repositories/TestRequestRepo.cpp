#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgRequestRepository.h"
#include "../../business_logic/rules/RequestRules.h"
#include "../../business_logic/models/ModelRequest.h"
#include "../../data_access/PostgresRepositories/PgClientRepository.h"
#include "../../data_access/PostgresRepositories/PgManagerRepository.h"
#include "../../data_access/PostgresRepositories/PgProductRepository.h"
#include "../../data_access/PostgresRepositories/PgUserRepository.h"


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

