#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

/**
 * C++ Mastery: STL Optimization and Templates
 * 
 * Using the Standard Template Library (STL) correctly can make or break a service.
 * Templates allow "Compile-time polymorphism", which is faster than virtual functions.
 */

struct Timer {
    std::chrono::high_resolution_clock::time_point start;
    Timer() : start(std::chrono::high_resolution_clock::now()) {}
    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "Time: " << duration << "us\n";
    }
};

void slow_vector() {
    std::cout << "Slow Vector (multiple reallocations): ";
    Timer t;
    std::vector<int> v;
    for(int i=0; i<10000; ++i) v.push_back(i);
}

void fast_vector() {
    std::cout << "Fast Vector (reserved memory): ";
    Timer t;
    std::vector<int> v;
    v.reserve(10000); // CRITICAL for optimization
    for(int i=0; i<10000; ++i) v.push_back(i);
}

// Template: Zero-overhead abstraction
template <typename T>
T add(T a, T b) { return a + b; }

int main() {
    slow_vector();
    fast_vector();
    
    std::cout << "\nTemplate add(int): " << add(5, 10) << "\n";
    std::cout << "Template add(double): " << add(5.5, 10.2) << "\n";
    
    return 0;
}
