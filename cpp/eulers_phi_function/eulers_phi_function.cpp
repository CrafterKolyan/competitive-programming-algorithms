#ifndef EULERS_PHI_FUNCTION_CPP_
#define EULERS_PHI_FUNCTION_CPP_

template<typename T>
T EulersPhiFunction(T number) {
    T result = number;

    // Case with prime 2 is considered separately (as an optimization)
    bool isEven = !(number & 1);
    while (!(number & 1)) {
        number >>= 1;
    }
    if (isEven) {
        result >>= 1;
    }

    for (T i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            do {
                number /= i;
            } while(number % i == 0);
            result -= result / i;
        }
    }
    if (number > 1) {
        result -= result / number;
    }
    return result;
}

#endif
