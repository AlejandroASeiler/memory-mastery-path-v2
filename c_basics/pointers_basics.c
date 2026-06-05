#include <stdio.h>

/**
 * C Basics: Pointers and Memory Addresses
 * 
 * In C, a pointer is a variable that stores the memory address of another variable.
 * Understanding pointers is crucial for system optimization and low-level control.
 */

void pointer_arithmetic() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // Points to the first element

    printf("\n--- Pointer Arithmetic ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: Value = %d, Address = %p\n", i, *(p + i), (void*)(p + i));
    }
}

int main() {
    int x = 42;
    int *ptr = &x; // ptr holds the address of x

    printf("--- Basic Pointers ---\n");
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value stored in ptr: %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    // Modifying value through pointer
    *ptr = 100;
    printf("New value of x after modification via pointer: %d\n", x);

    pointer_arithmetic();

    return 0;
}
