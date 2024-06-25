#include <gtest/gtest.h>
#include "sensor.hpp"

SensorManager manager;

TEST(checkAddedAQ, CorrectBehaviour) {

    Sensor testAQ(1, "AIRQUALITY", -3);
    manager.add(testAQ);

    EXPECT_TRUE(manager.airq.size() != 0) << "Not added";
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

