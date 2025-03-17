#include <iostream>
#include "algebra.h"

int main() {
    int a, b;
    std::cin >> a >> b;

    std::cout << "Greatest Common Factor = " << algebra::gcd(a, b) << std::endl;
    return 0;
}
