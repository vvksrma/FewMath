#include <iostream>
#include "algebra.h"
using namespace std;

int algebra::gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int shift = 0;
    while (((a | b) & 1) == 0) { // Both a and b are even
        a >>= 1;
        b >>= 1;
        shift++;
    }

    while ((a & 1) == 0) // Remove factors of 2 from a
        a >>= 1;

    while (b != 0) {
        while ((b & 1) == 0) // Remove factors of 2 from b
            b >>= 1;

        if (a > b)
            std::swap(a, b);

        b = b - a;
    }

    return a << shift;
}
