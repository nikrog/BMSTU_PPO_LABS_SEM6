#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgManagerRepository.h"
#include "../../business_logic/rules/ManagerRules.h"
#include "../../business_logic/models/ModelManager.h"
#include "../../data_access/PostgresRepositories/PgBankRepository.h"
#include "../../data_access/PostgresRepositories/PgClientRepository.h"
#include "../../data_access/PostgresRepositories/PgUserRepository.h"


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
