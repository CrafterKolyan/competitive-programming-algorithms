#ifndef EULERS_PHI_FUNCTION_CPP_
#define EULERS_PHI_FUNCTION_CPP_

template<typename IntegerType>
IntegerType EulersPhiFunction(IntegerType x) {
    IntegerType result = x;

    // Case with prime 2 is considered separately (as an optimization)
    bool isEven = !(x & 1);
    while (!(x & 1)) {
        x >>= 1;
    }
    if (isEven) {
        result >>= 1;
    }

    for (IntegerType i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            do {
                x /= i;
            } while(x % i == 0);
            result -= result / i;
        }
    }
    if (x > 1) {
        result -= result / x;
    }
    return result;
}

#endif
