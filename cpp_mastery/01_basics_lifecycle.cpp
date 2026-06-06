#include <iostream>
#include <string>

/**
 * C++ Mastery: References and Object Lifecycle
 * 
 * Before pointers, understand references. They are safer and often preferred.
 * Understanding when objects are created and destroyed is key to avoiding overhead.
 */

class Tracker {
public:
    std::string name;
    Tracker(std::string n) : name(n) { std::cout << "[Construct] " << name << "\n"; }
    ~Tracker() { std::cout << "[Destruct] " << name << "\n"; }
    
    // Copying is expensive!
    Tracker(const Tracker& other) : name(other.name + "_copy") {
        std::cout << "[Copy] " << name << "\n";
    }
};

// Pass by value: Creates a copy (Slow)
void process_by_value(Tracker t) {
    std::cout << "Processing " << t.name << " by value\n";
}

// Pass by reference: No copy (Fast)
void process_by_ref(const Tracker& t) {
    std::cout << "Processing " << t.name << " by reference\n";
}

int main() {
    std::cout << "--- Lifecycle Start ---\n";
    {
        Tracker local("LocalObj");
        process_by_ref(local);   // Fast
        process_by_value(local); // Slow: triggers copy
    } // LocalObj destroyed here
    std::cout << "--- Lifecycle End ---\n";

    return 0;
}
