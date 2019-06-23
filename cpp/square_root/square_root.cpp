#ifndef SQUARE_ROOT_CPP_
#define SQUARE_ROOT_CPP_

#include <cmath>
#include <limits>

double SquareRoot(double x) {
    if (x < 0.0 || std::isnan(x)) {
        return nan("");
    } else if (x == 0.0) {
        return 0.0;
    }
    unsigned long long initial_value = *reinterpret_cast<unsigned long long *>(&x);
    unsigned long long power = (initial_value >> 52) - 1023;
    if (power == 1024) {
        return std::numeric_limits<double>::infinity();
    }
    power /= 2;
    power += 1023;

    initial_value &= ~(0xFFFULL << 52);
    initial_value |= power << 52;

    double current_approximation = *reinterpret_cast<double *>(&initial_value);
    double previous_value = 0.0;
    double previous_previous_value = 0.0;
    // Newton's method
    while (current_approximation != previous_value && current_approximation != previous_previous_value) {
        previous_previous_value = previous_value;
        previous_value = current_approximation;
        current_approximation -= current_approximation / 2 - x / (2 * current_approximation);
    }
    if (current_approximation == previous_value) {
        return current_approximation;
    }
    return abs(current_approximation * current_approximation - x) < abs(previous_value * previous_value - x) ? current_approximation : previous_value;
}

#endif
