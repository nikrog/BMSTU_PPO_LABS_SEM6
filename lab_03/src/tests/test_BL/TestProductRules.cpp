#include <gtest/gtest.h>
#include "../../business_logic/models/ModelProduct.h"
#include "../../business_logic/rules/ProductRules.h"
#include "../../data_access/MockRepositories/MockProductRepository.h"

//Product tmpProduct = Product(id, 1, DEPOSIT, "first", 7.5, 180, 750,
 //                                50000, 1000000, ROUBLE, 0, 0);

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
