#include "algebra.h"
#include <omp.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <numeric>

using namespace std;
using namespace chrono;

const int NUM_RUNS = 100; // Number of runs for averaging

// Function to run benchmarks with averaging
template <typename Func>
void benchmark(const string& testName, Func func) {
    double totalTime = 0;
    for (int i = 0; i < NUM_RUNS; i++) {
        auto start = high_resolution_clock::now();
        func();
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;
        totalTime += elapsed.count();
    }
    cout << testName << " Average Time: " << (totalTime / NUM_RUNS) << " s" << endl;
}

int main() {
    vector<int> smallNumbers = {12, 18, 24, 36, 48, 60, 72, 84, 96};
    vector<int> mediumNumbers = {10012, 20018, 30024, 40036, 50048};
    vector<int> largeNumbers = {1000003, 2000007, 3000019, 4000031};
    vector<int> primeNumbers = {101, 103, 107, 109, 113, 127};
    vector<int> mixedNumbers = {12, 1000003, 18, 2000007, 24, 3000019};
    
    // Benchmark std::gcd
    benchmark("std::gcd (Small Numbers)", [&]() {
        int result = smallNumbers[0];
        for (size_t i = 1; i < smallNumbers.size(); i++) {
            result = gcd(result, smallNumbers[i]);
        }
    });

    benchmark("std::gcd (Medium Numbers)", [&]() {
        int result = mediumNumbers[0];
        for (size_t i = 1; i < mediumNumbers.size(); i++) {
            result = gcd(result, mediumNumbers[i]);
        }
    });

    benchmark("std::gcd (Large Numbers)", [&]() {
        int result = largeNumbers[0];
        for (size_t i = 1; i < largeNumbers.size(); i++) {
            result = gcd(result, largeNumbers[i]);
        }
    });
    
    benchmark("std::gcd (Prime Numbers)", [&]() {
        int result = primeNumbers[0];
        for (size_t i = 1; i < primeNumbers.size(); i++) {
            result = gcd(result, primeNumbers[i]);
        }
    });

    benchmark("std::gcd (Mixed Numbers)", [&]() {
        int result = mixedNumbers[0];
        for (size_t i = 1; i < mixedNumbers.size(); i++) {
            result = gcd(result, mixedNumbers[i]);
        }
    });

    // Benchmark FewMath GCD
    benchmark("FewMath GCD (Small Numbers)", [&]() {
        algebra::gcd(smallNumbers);
    });

    benchmark("FewMath GCD (Medium Numbers)", [&]() {
        algebra::gcd(mediumNumbers);
    });

    benchmark("FewMath GCD (Large Numbers)", [&]() {
        algebra::gcd(largeNumbers);
    });
    
    benchmark("FewMath GCD (Prime Numbers)", [&]() {
        algebra::gcd(primeNumbers);
    });

    benchmark("FewMath GCD (Mixed Numbers)", [&]() {
        algebra::gcd(mixedNumbers);
    });
    
    return 0;
}
