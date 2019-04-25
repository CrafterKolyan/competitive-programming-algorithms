#include "gtest/gtest.h"
#include "gtest/internal/custom/gtest.h"

#include "fenwick_tree.cpp"

#include <chrono>
#include <random>
#include <vector>

namespace FenwickTreeTests {
    constexpr int NUMBER_OF_RANDOMIZED_TESTS = 100;

    TEST(FenwickTree, Simple) {
        FenwickTree<int> tree(10);
        tree.Modify(0, 1);
        EXPECT_EQ(tree.Calculate(1), 1);
        tree.Modify(0, 1);
        tree.Modify(0, 1);
        EXPECT_EQ(tree.Calculate(1), 3);
        EXPECT_EQ(tree.Calculate(0, 1), 3);
    }

    TEST(FenwickTree, SumOfElements) {
        FenwickTree<int> tree(10);
        for (int i = 0; i < 10; ++i) {
            tree.Modify(i, i + 1);
        }
        EXPECT_EQ(tree.Calculate(10), 55);
        EXPECT_EQ(tree.Calculate(9, 10), 10);
        EXPECT_EQ(tree.Calculate(5, 7), 6 + 7);
        EXPECT_EQ(tree[3], 4);
    }

    TEST(FenwickTree, RandomizedLongLongElements) {
        std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> uniform_int_distribution(0, 255);
        std::vector<long long> v(100);
        FenwickTree<long long> tree(v.size());
        for (size_t i = 0; i < v.size(); ++i) {
            v[i] = uniform_int_distribution(generator);
            tree.Modify(i, v[i]);
        }

        std::uniform_int_distribution<> index_distribution(0, 100);
        for (int i = 0; i < NUMBER_OF_RANDOMIZED_TESTS; ++i) {
            int l = index_distribution(generator);
            int r = index_distribution(generator);
            if (l > r) {
                std::swap(l, r);
            }
            long long ans = 0;
            for (size_t i = l; i < r; ++i) {
                ans += v[i];
            }
            EXPECT_EQ(tree.Calculate(l, r), ans);
        }
    }

    TEST(FenwickTree, Resize) {
        FenwickTree<int> tree(10);
        for (int i = 0; i < 10; ++i) {
            tree.Modify(i, i + 1);
        }
        tree.resize(100);
        EXPECT_EQ(tree.Calculate(9, 100), 10);
        EXPECT_EQ(tree.Calculate(100), 55);
        EXPECT_EQ(tree.Calculate(56, 78), 0);

        tree.resize(4);
        EXPECT_EQ(tree.Calculate(4), 1 + 2 + 3 + 4);

        tree.resize(10);
        EXPECT_EQ(tree.Calculate(10), 1 + 2 + 3 + 4);
    }

    TEST(FenwickTree, ResizeEmptyTree) {
        FenwickTree<int> tree;
        tree.resize(10);
        tree.Modify(5, 5);
        tree.Modify(7, 7);
        EXPECT_EQ(tree.Calculate(5, 8), 5 + 7);
    }

    TEST(FenwickTree, Performance) {
        FenwickTree<long long> tree(100000);
        for (int i = 0; i < tree.size(); ++i) {
            tree.Modify(i, i + 1);
        }

        EXPECT_DURATION_LE( {
            for (long long i = 0; i < 100000; ++i) {
                EXPECT_EQ(tree.Calculate(i + 1), (i + 1) * (i + 2) / 2);
            }
        }, 1000);
    }
}
