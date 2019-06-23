#include "gtest/gtest.h"

#include "../binary_power/binary_power_tests.cpp"
#include "../eulers_phi_function/eulers_phi_function_tests.cpp"
#include "../fenwick_tree/fenwick_tree_tests.cpp"
#include "../square_root/square_root_tests.cpp"

#include <iostream>
#include <iomanip>

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
