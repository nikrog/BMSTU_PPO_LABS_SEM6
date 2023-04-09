#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgProductRepository.h"
#include "../../business_logic/rules/ProductRules.h"
#include "../../business_logic/models/ModelProduct.h"
#include "../../data_access/PostgresRepositories/PgBankRepository.h"


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
