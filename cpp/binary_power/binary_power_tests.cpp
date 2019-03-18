#include "gtest/gtest.h"

#include "binary_power.cpp"

#include <chrono>
#include <cmath>
#include <random>

namespace {
    constexpr int NUMBER_OF_RANDOMIZED_TESTS = 100;

    TEST(BinaryPower, PowerZero) {
        EXPECT_EQ(BinaryPower(1, 0), 1);
        EXPECT_EQ(BinaryPower(2, 0), 1);
        EXPECT_EQ(BinaryPower(3, 0), 1);
        EXPECT_EQ(BinaryPower(1024, 0), 1);
        EXPECT_EQ(BinaryPower(17, 0), 1);
        EXPECT_EQ(BinaryPower(1986247234, 0), 1);
    }

    TEST(BinaryPower, BaseZero) {
        EXPECT_EQ(BinaryPower(0, 1), 0);
        EXPECT_EQ(BinaryPower(0, 2), 0);
        EXPECT_EQ(BinaryPower(0, 5), 0);
        EXPECT_EQ(BinaryPower(0, 10), 0);
        EXPECT_EQ(BinaryPower(0, 100), 0);
        EXPECT_EQ(BinaryPower(0, 21345123), 0);
    }

    TEST(BinaryPower, BaseZeroModulo) {
        EXPECT_EQ(BinaryPower(0, 1, 1024), 0);
        EXPECT_EQ(BinaryPower(0, 2, 17), 0);
        EXPECT_EQ(BinaryPower(0, 5, 22), 0);
        EXPECT_EQ(BinaryPower(0, 10, 1928374), 0);
        EXPECT_EQ(BinaryPower(0, 100, 81237), 0);
        EXPECT_EQ(BinaryPower(0, 21345123, 1286464321), 0);
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
        EXPECT_EQ(BinaryPower(1, 5, 1488), 1);
        EXPECT_EQ(BinaryPower(1, 10, 228), 1);
        EXPECT_EQ(BinaryPower(1, 100, 322), 1);
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

    TEST(BinaryPower, BaseThreeModulo) {
        EXPECT_EQ(BinaryPower(3, 10, 100000), 59049);
        EXPECT_EQ(BinaryPower(3, 1000, 103), 61);
        EXPECT_EQ(BinaryPower<long long>(3, 2134686234, 148832249), 88892953);
    }

    TEST(BinaryPower, PowerTwo) {
        EXPECT_EQ(BinaryPower(5, 2), 25);
        EXPECT_EQ(BinaryPower(17, 2), 289);
        EXPECT_EQ(BinaryPower(32, 2), 1024);
        EXPECT_EQ(BinaryPower(-1, 2), 1);
        EXPECT_EQ(BinaryPower(-17, 2), 289);
        EXPECT_EQ(BinaryPower(0, 2), 0);
    }

    TEST(BinaryPower, Simple) {
        EXPECT_EQ(BinaryPower(5, 3), 125);
        EXPECT_EQ(BinaryPower(28, 6), 481890304);
        EXPECT_EQ(BinaryPower(-28, 6), 481890304);
        EXPECT_EQ(BinaryPower(-28, 5), -17210368);
        EXPECT_EQ(BinaryPower<long long>(1488, 3), 3294646272LL);
    }

    TEST(BinaryPower, SimpleModulo) {
        EXPECT_EQ(BinaryPower(5, 3, 100), 25);
        EXPECT_EQ(BinaryPower(28, 6, 10000), 304);
        EXPECT_EQ(BinaryPower(10028, 6, 10000), 304);
        EXPECT_EQ(BinaryPower(28, 5, 17210369), 17210368);
        EXPECT_EQ(BinaryPower<long long>(1488, 3, 998779), 673130);
    }

    TEST(BinaryPower, CornerCases) {
        EXPECT_EQ(BinaryPower(-2, 31), -2147483648);
        EXPECT_EQ(BinaryPower(2147483647, 1), 2147483647);
        EXPECT_EQ(BinaryPower(1, 2147483647), 1);
        EXPECT_EQ(BinaryPower(0, 2147483647), 0);
    }

    TEST(BinaryPower, CornerCasesModulo) {
        EXPECT_EQ(BinaryPower(2, 1000, 1), 0);
        EXPECT_EQ(BinaryPower<long long>(2147483647, 2147483647, 2147483647), 0);
        EXPECT_EQ(BinaryPower<long long>(2147483646, 2147483646, 2147483647), 1);
        EXPECT_EQ(BinaryPower<long long>(2147483646, 2147483647, 2147483647), 2147483646);
    }

    TEST(BinaryPower, Randomized) {
        std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> uniform_int_distribution(0, 9);
        for (int i = 0; i < NUMBER_OF_RANDOMIZED_TESTS; ++i) {
            const int base = uniform_int_distribution(generator);
            const int power = uniform_int_distribution(generator);
            EXPECT_DOUBLE_EQ(BinaryPower(base, power), pow(base, power));
        }
    }
}
