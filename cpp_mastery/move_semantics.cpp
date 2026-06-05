#include <iostream>
#include <vector>
#include <string>
#include <chrono>

/**
 * C++ Mastery: Move Semantics and Optimization
 * 
 * Move semantics (C++11) allows "stealing" resources from temporary objects
 * instead of copying them, significantly improving performance in SaaS/Systems.
 */

class BigData {
public:
    size_t size;
    int* data;

    // Constructor
    BigData(size_t s) : size(s) {
        data = new int[size];
        std::cout << "Allocated " << size << " integers\n";
    }

    // Copy Constructor (Expensive)
    BigData(const BigData& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) data[i] = other.data[i];
        std::cout << "Copy Constructor called (Deep Copy)\n";
    }

    // Move Constructor (Cheap)
    BigData(BigData&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move Constructor called (Resource Stolen)\n";
    }

    ~BigData() {
        delete[] data;
        if (data) std::cout << "Destructor: Memory freed\n";
    }
};

int main() {
    std::cout << "--- Creating Vector of BigData ---\n";
    std::vector<BigData> vec;
    vec.reserve(2); // Prevent reallocations for this demo

    std::cout << "\nPushing temporary (rvalue):\n";
    vec.push_back(BigData(1000)); // Should trigger Move

    std::cout << "\nPushing existing object (lvalue):\n";
    BigData b(2000);
    vec.push_back(b); // Should trigger Copy

    std::cout << "\nPushing with std::move:\n";
    vec.push_back(std::move(b)); // Should trigger Move

    return 0;
}
