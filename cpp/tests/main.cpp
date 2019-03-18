#include "gtest/gtest.h"

#include "../binary_power/binary_power_tests.cpp"
#include "../eulers_phi_function/eulers_phi_function_tests.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
