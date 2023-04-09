#include <gtest/gtest.h>

#include "../../data_access/PostgresRepositories/PgBankRepository.h"
#include "../../business_logic/rules/BankRules.h"
#include "../../business_logic/models/ModelBank.h"

TEST(TestPgBankRepo, TestAddandDeleteBank)
{
    ConnectionParams connectParams = ConnectionParams("postgres", "localhost", "postgres", "admin", 5435);
    PgBankRepository rep = PgBankRepository(connectParams);
    BankRules brules(rep);
    int id = brules.addBank({.name="Alfa", .license_num=1236, .address="Street 54",
     .email="alfa@alfa.ru", .phone="+749567890999", .website="alfa.ru"});
    Bank tmpBank = brules.getBank(id);
    EXPECT_EQ(tmpBank.getID(), id);
    EXPECT_EQ(tmpBank.getLicenseNum(), 1236);
    EXPECT_EQ(tmpBank.getName(), "Alfa");
    brules.deleteBank(id);
    ASSERT_THROW(brules.getBank(id), BankNotFoundException);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}