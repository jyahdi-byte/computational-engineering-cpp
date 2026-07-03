#include <iostream>
#include <cmath>
#include <cassert>

double f(double x) {
    return x * x * x;
}

int main() {
    double x;
    int k_max;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter number of h-values to test: ";
    std::cin >> k_max;
    assert(k_max >= 1);
    double exact = 3 * x * x;

    for (int k = 1; k <= k_max; ++k) {
        double h = std::pow(10.0, -k);
        double slope = (f(x + h) - f(x - h)) / (2.0 * h);
        std::cout << "h = " << h
                  << "    slope = " << slope
                  << "    error = " << std::abs(slope - exact) << "\n";
    }
    return 0;
}