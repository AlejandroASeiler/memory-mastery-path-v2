#include <iostream>
#include <memory>
#include <vector>

/**
 * C++ Mastery: Smart Pointers and RAII
 * 
 * Resource Acquisition Is Initialization (RAII) is the core of modern C++.
 * Smart pointers (unique_ptr, shared_ptr) automate memory management to prevent leaks.
 */

class Resource {
public:
    Resource(int id) : id(id) { std::cout << "Resource " << id << " acquired\n"; }
    ~Resource() { std::cout << "Resource " << id << " released\n"; }
    void do_something() { std::cout << "Resource " << id << " is working\n"; }
private:
    int id;
};

void unique_ptr_demo() {
    std::cout << "\n--- std::unique_ptr Demo ---\n";
    // unique_ptr: exclusive ownership
    std::unique_ptr<Resource> res1 = std::make_unique<Resource>(101);
    res1->do_something();
    
    // std::unique_ptr<Resource> res2 = res1; // Error: cannot copy unique_ptr
    std::unique_ptr<Resource> res2 = std::move(res1); // Ownership transferred
    if (!res1) std::cout << "res1 is now null\n";
    res2->do_something();
} // res2 goes out of scope, Resource 101 is released automatically

void shared_ptr_demo() {
    std::cout << "\n--- std::shared_ptr Demo ---\n";
    std::shared_ptr<Resource> s1 = std::make_shared<Resource>(202);
    {
        std::shared_ptr<Resource> s2 = s1; // Shared ownership
        std::cout << "Reference count: " << s1.use_count() << "\n";
        s2->do_something();
    } // s2 goes out of scope, but Resource 202 is NOT released yet
    std::cout << "Reference count after inner scope: " << s1.use_count() << "\n";
} // s1 goes out of scope, Resource 202 is released

int main() {
    unique_ptr_demo();
    shared_ptr_demo();
    return 0;
}
