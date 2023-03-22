#include <gtest/gtest.h>
#include "../../business_logic/models/ModelRequest.h"
#include "../../business_logic/rules/RequestRules.h"
#include "../../data_access/MockRepositories/MockRequestRepository.h"

//Request tmpRequest = Request(id,1,1,1,10000, 365, 10, OPENED);

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}