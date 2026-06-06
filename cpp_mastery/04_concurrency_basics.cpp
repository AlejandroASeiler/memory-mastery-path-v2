#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

/**
 * C++ Mastery: Concurrency and Multithreading
 * 
 * To optimize services (SaaS/Backends), you must handle multiple tasks simultaneously.
 * 1. std::thread: Basic unit of execution.
 * 2. std::mutex: Protect shared data from race conditions.
 * 3. std::atomic: Low-level synchronization for high performance.
 */

std::mutex mtx;
int shared_counter = 0;
std::atomic<int> atomic_counter(0);

void increment_with_mutex(int id) {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // RAII lock
        shared_counter++;
    }
    std::cout << "Thread " << id << " finished (mutex)\n";
}

void increment_atomic(int id) {
    for (int i = 0; i < 1000; ++i) {
        atomic_counter++; // Thread-safe without locks! (Faster)
    }
    std::cout << "Thread " << id << " finished (atomic)\n";
}

int main() {
    std::vector<std::thread> threads;

    std::cout << "--- Starting Mutex Threads ---\n";
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(increment_with_mutex, i);
    }
    for (auto& t : threads) t.join();
    threads.clear();

    std::cout << "--- Starting Atomic Threads ---\n";
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(increment_atomic, i);
    }
    for (auto& t : threads) t.join();

    std::cout << "\nFinal Shared Counter (Mutex): " << shared_counter << "\n";
    std::cout << "Final Atomic Counter: " << atomic_counter << "\n";

    return 0;
}
