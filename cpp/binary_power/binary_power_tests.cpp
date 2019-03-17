#include "gtest/gtest.h"

#include "binary_power.cpp"

namespace {
    TEST(BinaryPower, PowerZero) {
        EXPECT_EQ(BinaryPower(1, 0), 1);
        EXPECT_EQ(BinaryPower(2, 0), 1);
        EXPECT_EQ(BinaryPower(3, 0), 1);
        EXPECT_EQ(BinaryPower(1024, 0), 1);
        EXPECT_EQ(BinaryPower(17, 0), 1);
        EXPECT_EQ(BinaryPower(1986247234, 0), 1);
    }

    TEST(BinaryPower, BaseOne) {
        EXPECT_EQ(BinaryPower(1, 1), 1);
        EXPECT_EQ(BinaryPower(1, 2), 1);
        EXPECT_EQ(BinaryPower(1, 5), 1);
        EXPECT_EQ(BinaryPower(1, 10), 1);
        EXPECT_EQ(BinaryPower(1, 100), 1);
        EXPECT_EQ(BinaryPower(1, 21345123), 1);
    }

    TEST(BinaryPower, BaseOneModulo) {
        EXPECT_EQ(BinaryPower(1, 1, 1024), 1);
        EXPECT_EQ(BinaryPower(1, 2, 1024), 1);
        EXPECT_EQ(BinaryPower(1, 5, 1024), 1);
        EXPECT_EQ(BinaryPower(1, 10, 1024), 1);
        EXPECT_EQ(BinaryPower(1, 100, 1024), 1);
    }

    TEST(BinaryPower, BaseTwo) {
        EXPECT_EQ(BinaryPower(2, 1), 2);
        EXPECT_EQ(BinaryPower(2, 3), 8);
        EXPECT_EQ(BinaryPower(2, 10), 1024);
        EXPECT_EQ(BinaryPower(2, 16), 65536);
    }

    TEST(BinaryPower, BaseTwoModulo) {
        EXPECT_EQ(BinaryPower(2, 1, 10), 2);
        EXPECT_EQ(BinaryPower(2, 3, 5), 3);
        EXPECT_EQ(BinaryPower(2, 10, 128), 0);
        EXPECT_EQ(BinaryPower(2, 16, 17), 1);
        EXPECT_EQ(BinaryPower(2, 1000, 228), 112);
    }
}
