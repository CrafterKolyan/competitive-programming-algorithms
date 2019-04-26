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
    FenwickTree(size_t size) : fenwick_tree_(size, T()) {}

    template<typename ForwardIterator>
    FenwickTree(ForwardIterator begin, ForwardIterator end) {
        fenwick_tree_.push_back(T());
        while (begin != end) {
            fenwick_tree_.push_back(binary_operation_(fenwick_tree_.back(), *begin));
            ++begin;
        }

        T previous_value = fenwick_tree_.back();
        for (size_t i = fenwick_tree_.size() - 1; i; --i) {
            previous_value = inverted_binary_operation_(previous_value, fenwick_tree_[i & (i - 1)]);
            std::swap(fenwick_tree_[i - 1], previous_value);
        }
        fenwick_tree_.resize(fenwick_tree_.size() - 1);
    }

    void Modify(size_t index, const T &val) {
        for (; index < fenwick_tree_.size(); index |= index + 1) {
            fenwick_tree_[index] = binary_operation_(fenwick_tree_[index], val);
        }
    }

    T Calculate(size_t index) const {
        T ret = T();
        for (; index--; index &= index + 1) {
            ret = binary_operation_(fenwick_tree_[index], ret);
        }
        return ret;
    }

    T Calculate(size_t left, size_t right) const {
        return inverted_binary_operation_(Calculate(right), Calculate(left));
    }

    T operator[](size_t index) const {
        return Calculate(index, index + 1);
    }

    size_t size() const {
        return fenwick_tree_.size();
    }

    void resize(size_t size) {
        size_t initial_size = fenwick_tree_.size();
        fenwick_tree_.resize(size);
        for (size_t i = initial_size; i < size; ++i) {
            fenwick_tree_[i] = Calculate(i & (i + 1), i);
        }
    }
};

#endif
