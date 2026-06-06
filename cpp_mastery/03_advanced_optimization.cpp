#include <iostream>
#include <string>
#include <string_view>

/**
 * C++ Mastery: Advanced Optimization
 * 
 * 1. std::string_view (C++17): Avoids allocations when slicing strings.
 * 2. Memory Alignment: How struct layout affects performance and size.
 */

// Memory Alignment Example
struct Unoptimized {
    char a;    // 1 byte
    double b;  // 8 bytes
    int c;     // 4 bytes
}; // Likely 24 bytes due to padding

struct Optimized {
    double b;  // 8 bytes
    int c;     // 4 bytes
    char a;    // 1 byte
}; // Likely 16 bytes (Better cache usage!)

// string_view optimization
void print_string(std::string s) { // Copy
    (void)s;
}

void print_string_view(std::string_view sv) { // No copy, just a pointer + length
    (void)sv;
}

int main() {
    std::cout << "--- Memory Alignment ---\n";
    std::cout << "Size of Unoptimized: " << sizeof(Unoptimized) << " bytes\n";
    std::cout << "Size of Optimized: " << sizeof(Optimized) << " bytes\n";

    std::cout << "\n--- string_view Optimization ---\n";
    std::string large_string = "This is a very long string that would be expensive to copy multiple times";
    
    // In a loop or high-frequency service, string_view saves massive CPU/Memory
    for(int i=0; i<1000; ++i) {
        print_string_view(large_string); 
    }
    std::cout << "Processed large string 1000 times with zero copies using string_view.\n";

    return 0;
}
