#include <stdio.h>
#include <stdint.h>

/**
 * Advanced C: Bit Manipulation and Function Pointers
 * 
 * 1. Bitwise operations: Crucial for optimizing flags and low-level protocols.
 * 2. Function Pointers: Foundation of callbacks and polymorphism in C.
 */

// Bit Manipulation
void bit_demo() {
    uint8_t flags = 0;
    const uint8_t FLAG_READ  = 0x01; // 0000 0001
    const uint8_t FLAG_WRITE = 0x02; // 0000 0010
    const uint8_t FLAG_EXEC  = 0x04; // 0000 0100

    printf("--- Bit Manipulation ---\n");
    flags |= FLAG_READ;  // Set READ
    flags |= FLAG_WRITE; // Set WRITE
    
    if (flags & FLAG_READ) printf("Read flag is set\n");
    if (!(flags & FLAG_EXEC)) printf("Exec flag is NOT set\n");

    flags &= ~FLAG_WRITE; // Clear WRITE
    printf("Flags after clearing WRITE: %02X\n", flags);
}

// Function Pointers
typedef int (*Operation)(int, int);

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

void execute_op(Operation op, int a, int b) {
    printf("Result of operation: %d\n", op(a, b));
}

int main() {
    bit_demo();

    printf("\n--- Function Pointers ---\n");
    execute_op(add, 10, 5);
    execute_op(multiply, 10, 5);

    return 0;
}
