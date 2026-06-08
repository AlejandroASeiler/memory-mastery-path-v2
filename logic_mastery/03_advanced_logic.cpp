#include <iostream>
#include <algorithm>
#include <vector>

/**
 * Logic Mastery: Advanced Optimization (Branchless Programming)
 * 
 * Modern CPUs use "Branch Prediction". If an "if" statement is unpredictable, 
 * it slows down the CPU. Branchless programming uses math to avoid "if"s.
 */

// Branchy version (Slower due to mispredictions)
int max_branchy(int a, int b) {
    if (a > b) return a;
    return b;
}

// Branchless version (Faster in high-performance loops)
int max_branchless(int a, int b) {
    return a ^ ((a ^ b) & -(a < b));
}

// Compile-time Logic (Metaprogramming)
template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    int x = 100, y = 200;
    
    std::cout << "--- Branchless Logic ---\n";
    std::cout << "Max of " << x << " and " << y << " is: " << max_branchless(x, y) << "\n";

    std::cout << "\n--- Compile-time Logic (Templates) ---\n";
    std::cout << "Factorial of 5 (calculated at compile time): " << Factorial<5>::value << "\n";

    return 0;
}
