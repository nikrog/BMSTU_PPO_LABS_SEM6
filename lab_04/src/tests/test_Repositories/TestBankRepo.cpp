#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgBankRepository.h"
#include "../../business_logic/rules/BankRules.h"
#include "../../business_logic/models/ModelBank.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}