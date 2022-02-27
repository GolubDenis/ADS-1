// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value == 1) {
        return false;
    }
    for (uint64_t i = 2; i <= value/2; i++)
        if (value % i == 0)
            return false;
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 1) {
        return 2;
    }
    uint64_t i = 2;
    uint64_t a = 1;
    do {
        i = nextPrime(i);
        a++;
    } while (a < n);
    return i;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t i = value;
    do {
        i += 1;
    } while (!checkPrime(i));
             return i;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    uint64_t i = 0;
    do {
        sum += i;
        i = nextPrime(i);
    } while (i < hbound);
    return sum;
}
