#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <vector>

class algebra {
public:
    /**
     * Computes the GCD of two integers.
     */
    static int gcd(int a, int b);

    /**
     * Computes the GCD of a single array.
     */
    static int gcd(const std::vector<int>& nums);

    /**
     * Computes the GCD element-wise for two arrays.
     */
    static std::vector<int> gcd(const std::vector<int>& a, const std::vector<int>& b);
};

#endif // ALGEBRA_H
