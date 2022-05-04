// tests.cpp

#include <gtest/gtest.h>
#include "Utils.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(roundToPeriod, ToCeiling_15min) {
	unsigned long long result = 1648062910000;
	unsigned long long output = TimeUtils::roundToPeriod(1648062697000, 15, false, 10);
	EXPECT_EQ(result, output);
	EXPECT_TRUE(true);
}

TEST(roundToPeriod, ToFloor_15min) {
	unsigned long long result = 1648062010000;
	unsigned long long output = TimeUtils::roundToPeriod(1648062697000, 15, true, 10);
	EXPECT_EQ(result, output);
	EXPECT_TRUE(true);
}

TEST(roundToPeriod, ToFloor_1min) {
	unsigned long long result = 1648062670000;
	unsigned long long output = TimeUtils::roundToPeriod(1648062697000, 1, true, 10);
	EXPECT_EQ(result, output);
	EXPECT_TRUE(true);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


