#include "algebra.h"
#include <omp.h>
#include <vector>
#include <algorithm>

/**
 * Euclidean Algorithm (Fastest for Small Numbers)
 */
int gcd_euclidean(int a, int b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

/**
 * Binary GCD Algorithm (Efficient for Medium and Large Numbers)
 */
int gcd_binary(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int shift = 0;
    while (((a | b) & 1) == 0) {  
        a >>= 1;
        b >>= 1;
        shift++;
    }

    while ((a & 1) == 0) a >>= 1;

    while (b != 0) {
        while ((b & 1) == 0) b >>= 1;
        if (a > b) std::swap(a, b);
        b -= a;
    }

    return a << shift;
}

/**
 * Hybrid GCD Selection (Automatically Chooses Best Algorithm)
 */
int algebra::gcd(int a, int b) {
    if (a == b) return a;
    
    // Use Euclidean algorithm for small numbers
    if (std::max(a, b) < 10'000) return gcd_euclidean(a, b);
    
    // Use Binary GCD for larger numbers
    return gcd_binary(a, b);
}

/**
 * Computes GCD of an array (Parallelized for Large Arrays)
 */
int algebra::gcd(const std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int result = nums[0];

    // If array is small, use serial Euclidean approach
    if (nums.size() < 10) {
        for (size_t i = 1; i < nums.size(); i++) {
            result = gcd(result, nums[i]);
            if (result == 1) return 1;  // Early exit
        }
        return result;
    }

    // Large arrays: Use Parallelized GCD Reduction
    #pragma omp parallel
    {
        int local_result = result;
        #pragma omp for nowait
        for (size_t i = 1; i < nums.size(); i++) {
            local_result = gcd(local_result, nums[i]);
            if (local_result == 1) break;
        }

        #pragma omp critical
        {
            result = gcd(result, local_result);
        }
    }

    return result;
}

/**
 * Computes GCD element-wise for two arrays (Parallelized for Large Arrays)
 */
std::vector<int> algebra::gcd(const std::vector<int>& a, const std::vector<int>& b) {
    size_t size = std::min(a.size(), b.size());
    std::vector<int> result(size);

    // Small arrays: Use serial approach
    if (size < 10) {
        for (size_t i = 0; i < size; i++) {
            result[i] = gcd(a[i], b[i]);
        }
        return result;
    }

    // Large arrays: Parallelized
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++) {
        result[i] = gcd(a[i], b[i]);
    }

    return result;
}