#ifndef BINARY_POWER_CPP_
#define BINARY_POWER_CPP_

template<typename IntegerType>
IntegerType BinaryPower(IntegerType base, IntegerType power) {
    IntegerType result = 1;
    while (power) {
        if (power & 1) {
            result *= base;
        }
        power >>= 1;
        base *= base;
    }
    return result;
}

template<typename IntegerType>
IntegerType BinaryPower(IntegerType base, IntegerType power, IntegerType modulo) {
    IntegerType result = 1;
    while (power) {
        if (power & 1) {
            result *= base;
            result %= modulo;
        }
        power >>= 1;
        base *= base;
        base %= modulo;
    }
    return result;
}

#endif
