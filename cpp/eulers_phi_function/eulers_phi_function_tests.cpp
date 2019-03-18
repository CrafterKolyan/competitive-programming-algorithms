#include "gtest/gtest.h"

#include "eulers_phi_function.cpp"

namespace EulerPhiFunctionTests {
    TEST(EulersPhiFunction, FirstNumbers) {
        EXPECT_EQ(EulersPhiFunction(1), 1);
        EXPECT_EQ(EulersPhiFunction(2), 1);
        EXPECT_EQ(EulersPhiFunction(3), 2);
        EXPECT_EQ(EulersPhiFunction(4), 2);
        EXPECT_EQ(EulersPhiFunction(5), 4);
        EXPECT_EQ(EulersPhiFunction(6), 2);
        EXPECT_EQ(EulersPhiFunction(7), 6);
        EXPECT_EQ(EulersPhiFunction(8), 4);
        EXPECT_EQ(EulersPhiFunction(9), 6);
        EXPECT_EQ(EulersPhiFunction(10), 4);
        EXPECT_EQ(EulersPhiFunction(11), 10);
    }

    TEST(EulersPhiFunction, PrimeNumbers) {
        EXPECT_EQ(EulersPhiFunction(1237), 1236);
        EXPECT_EQ(EulersPhiFunction(4663), 4662);
        EXPECT_EQ(EulersPhiFunction(423557), 423556);
        EXPECT_EQ(EulersPhiFunction(1000000007), 1000000006);
        EXPECT_EQ(EulersPhiFunction(1000000009), 1000000008);
        EXPECT_EQ(EulersPhiFunction(1073741827), 1073741826);
    }

    TEST(EulersPhiFunction, PrimePowerNumbers) {
        EXPECT_EQ(EulersPhiFunction(1024), 512);
        EXPECT_EQ(EulersPhiFunction(59049), 59049 / 3 * 2);
        EXPECT_EQ(EulersPhiFunction(1237 * 1237), 1237 * 1236);
        EXPECT_EQ(EulersPhiFunction(4663 * 4663), 4663 * 4662);
    }

    TEST(EulersPhiFunction, ComplexNumbers) {
        EXPECT_EQ(EulersPhiFunction(12), 4);
        EXPECT_EQ(EulersPhiFunction(15), 8);
        EXPECT_EQ(EulersPhiFunction(60), 16);
        EXPECT_EQ(EulersPhiFunction(100), 40);
        EXPECT_EQ(EulersPhiFunction(125), 100);
        EXPECT_EQ(EulersPhiFunction(98017920), 17694720);
        EXPECT_EQ(EulersPhiFunction(135783456), 44405504);
    }

    TEST(EulersPhiFunction, CarmichaelNumbers) {
        EXPECT_EQ(EulersPhiFunction(561), 320);
        EXPECT_EQ(EulersPhiFunction(1105), 768);
        EXPECT_EQ(EulersPhiFunction(1729), 1296);
        EXPECT_EQ(EulersPhiFunction(2465), 1792);
        EXPECT_EQ(EulersPhiFunction(2821), 2160);
        EXPECT_EQ(EulersPhiFunction(6601), 5280);
        EXPECT_EQ(EulersPhiFunction(8911), 7128);
        EXPECT_EQ(EulersPhiFunction(41041), 28800);
        EXPECT_EQ(EulersPhiFunction(101101), 72000);
        EXPECT_EQ(EulersPhiFunction(825265), 497664);
    }
}
