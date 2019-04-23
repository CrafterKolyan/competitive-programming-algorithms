#ifndef FENWICK_TREE_CPP_
#define FENWICK_TREE_CPP_

#include <algorithm>
#include <cstddef>
#include <functional>
#include <vector>

template<typename T, typename BinaryOperation = std::plus<T>, typename InvertedBinaryOperation = std::minus<T>>
class FenwickTree {
    std::vector<T> fenwick_tree_;
    BinaryOperation binary_operation_ = BinaryOperation();
    InvertedBinaryOperation inverted_binary_operation_ = InvertedBinaryOperation();

public:
    FenwickTree() {};
    FenwickTree(size_t size) : fenwick_tree_(size + 1, T()) {}

    void Modify(size_t index, const T &val) {
        for (; ++index < fenwick_tree_.size(); index |= index - 1) {
            fenwick_tree_[index] = binary_operation_(fenwick_tree_[index], val);
        }
    }

    T Calculate(size_t index) const {
        T ret = T();
        for (; index > 0; index &= index - 1) {
            ret = binary_operation_(ret, fenwick_tree_[index]);
        }
        return ret;
    }

    T Calculate(size_t left, size_t right) const {
        return inverted_binary_operation_(Calculate(right), Calculate(left));
    }

    T operator[](size_t index) const {
        return Calculate(index, index + 1);
    }

    void Resize(size_t size) {
        size_t initial_size = fenwick_tree_.size();
        if (size + 1 <= initial_size) {
            fenwick_tree_.resize(size + 1);
            return;
        }
        fenwick_tree_.resize(size + 1);
        for (size_t i = std::max(initial_size, static_cast<size_t>(0)); i <= size; ++i) {
            fenwick_tree_[i] = Calculate(i & (i - 1), i - 1);
        }
    }
};

#endif
