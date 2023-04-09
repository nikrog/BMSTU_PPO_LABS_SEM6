#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgClientRepository.h"
#include "../../business_logic/rules/ClientRules.h"
#include "../../business_logic/models/ModelClient.h"
#include "../../business_logic/models/ModelUser.h"
#include "../../business_logic/models/ModelManager.h"
#include "../../data_access/PostgresRepositories/PgManagerRepository.h"
#include "../../data_access/PostgresRepositories/PgUserRepository.h"


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
