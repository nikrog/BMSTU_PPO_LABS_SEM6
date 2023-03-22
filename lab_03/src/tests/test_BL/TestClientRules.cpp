#include <gtest/gtest.h>
#include "../../business_logic/models/ModelClient.h"
#include "../../business_logic/rules/ClientRules.h"
#include "../../data_access/MockRepositories/MockClientRepository.h"

//Client tmpClient = Client(id, 1, "abc", "abc", "abc", 123456,
     //                         1975, "Komarovo", "t@mail.ru", "+7903617890");
     
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}