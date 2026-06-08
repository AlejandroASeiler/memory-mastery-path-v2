#include <stdio.h>
#include <stdbool.h>

/**
 * Logic Mastery: Basic Boolean Algebra and Truth Tables
 * 
 * Understanding how the CPU evaluates conditions is the first step 
 * towards writing optimized code.
 */

void print_truth_table_and() {
    printf("--- Truth Table: AND (&&) ---\n");
    printf("A | B | A && B\n");
    printf("--|---|-------\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("%d | %d |   %d\n", a, b, a && b);
        }
    }
}

void print_truth_table_or() {
    printf("\n--- Truth Table: OR (||) ---\n");
    printf("A | B | A || B\n");
    printf("--|---|-------\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("%d | %d |   %d\n", a, b, a || b);
        }
    }
}

void short_circuit_demo() {
    printf("\n--- Short-Circuit Logic ---\n");
    int x = 0;
    // In (0 && ++x), ++x is NEVER executed because 0 is already false.
    if (0 && ++x) {} 
    printf("Value of x after (0 && ++x): %d (Expected 0)\n", x);

    // In (1 || ++x), ++x is NEVER executed because 1 is already true.
    if (1 || ++x) {}
    printf("Value of x after (1 || ++x): %d (Expected 0)\n", x);
}

int main() {
    print_truth_table_and();
    print_truth_table_or();
    short_circuit_demo();
    return 0;
}
