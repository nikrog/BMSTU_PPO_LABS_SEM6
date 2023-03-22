#include <gtest/gtest.h>
#include "../../business_logic/models/ModelBank.h"
#include "../../business_logic/rules/BankRules.h"
#include "../../data_access/MockRepositories/MockBankRepository.h"

//Bank tmpBank = Bank(id, "VTB", 1234, "Street 9", "vtb@vtb.ru",
 //                       "+749567890555", "vtb.ru");
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}