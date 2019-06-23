#include "gtest/gtest.h"
#include "gtest/internal/custom/gtest.h"

#include "square_root.cpp"

#include <cmath>
#include <limits>

namespace SquareRootTests {
    TEST(SquareRoot, SquareValues) {
        EXPECT_DOUBLE_EQ(SquareRoot(-0.0), 0.0);
        EXPECT_DOUBLE_EQ(SquareRoot(0.0), 0.0);
        EXPECT_DOUBLE_EQ(SquareRoot(1.0), 1.0);
        EXPECT_DOUBLE_EQ(SquareRoot(4.0), 2.0);
        EXPECT_DOUBLE_EQ(SquareRoot(9.0), 3.0);
        EXPECT_DOUBLE_EQ(SquareRoot(16.0), 4.0);
        EXPECT_DOUBLE_EQ(SquareRoot(25.0), 5.0);
        EXPECT_DOUBLE_EQ(SquareRoot(100.0), 10.0);
        EXPECT_DOUBLE_EQ(SquareRoot(1e12), 1e6);

        EXPECT_DOUBLE_EQ(SquareRoot(0.01), 0.1);
        EXPECT_DOUBLE_EQ(SquareRoot(0.04), 0.2);
        EXPECT_DOUBLE_EQ(SquareRoot(1e-10), 1e-5);
    }

    TEST(SquareRoot, LessThanZero) {
        EXPECT_TRUE(std::isnan(SquareRoot(-1.0)));
        EXPECT_TRUE(std::isnan(SquareRoot(-2.0)));
        EXPECT_TRUE(std::isnan(SquareRoot(-4.0)));
        EXPECT_TRUE(std::isnan(SquareRoot(-3.0)));
        EXPECT_TRUE(std::isnan(SquareRoot(-10.0)));
        EXPECT_TRUE(std::isnan(SquareRoot(-1234897234.5238947923)));

        EXPECT_TRUE(std::isnan(SquareRoot(-1e-5)));
        EXPECT_TRUE(std::isnan(SquareRoot(-1e100)));

        EXPECT_TRUE(std::isnan(SquareRoot(std::numeric_limits<double>::lowest())));
    }

    TEST(SquareRoot, MathSqrtEquality) {
        EXPECT_DOUBLE_EQ(SquareRoot(2.0), sqrt(2.0));
        EXPECT_DOUBLE_EQ(SquareRoot(3.0), sqrt(3.0));
        EXPECT_DOUBLE_EQ(SquareRoot(10.0), sqrt(10.0));
        EXPECT_DOUBLE_EQ(SquareRoot(std::numeric_limits<double>::max()), sqrt(std::numeric_limits<double>::max()));

        EXPECT_DOUBLE_EQ(SquareRoot(585.0), sqrt(585.0));
        EXPECT_DOUBLE_EQ(SquareRoot(323846238745.234235), sqrt(323846238745.234235));
        EXPECT_DOUBLE_EQ(SquareRoot(540989.12), sqrt(540989.12));
    }

    TEST(SquareRoot, Infinity) {
        EXPECT_TRUE(std::isnan(SquareRoot(-std::numeric_limits<double>::infinity())));
        EXPECT_DOUBLE_EQ(SquareRoot(std::numeric_limits<double>::infinity()), sqrt(std::numeric_limits<double>::infinity()));
    }

    TEST(SquareRoot, Nan) {
        EXPECT_TRUE(std::isnan(SquareRoot(nan(""))));
    }
}
