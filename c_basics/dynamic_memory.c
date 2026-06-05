#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * C Basics: Dynamic Memory Management
 * 
 * Using malloc, calloc, realloc, and free.
 * Manual memory management is the foundation of C optimization.
 */

typedef struct {
    int id;
    char *name;
} Entity;

void manage_entity() {
    printf("\n--- Dynamic Struct Allocation ---\n");
    
    // Allocate memory for the struct
    Entity *e = (Entity *)malloc(sizeof(Entity));
    if (e == NULL) return;

    e->id = 1;
    // Allocate memory for the string inside the struct
    e->name = (char *)malloc(20 * sizeof(char));
    strcpy(e->name, "Manus Agent");

    printf("Entity ID: %d, Name: %s\n", e->id, e->name);

    // CRITICAL: Free in reverse order of allocation
    free(e->name);
    free(e);
    printf("Memory freed successfully.\n");
}

int main() {
    int n = 5;
    
    // malloc: allocates uninitialized memory
    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    printf("--- Malloc Array ---\n");
    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // realloc: changes the size of previously allocated memory
    n = 10;
    arr = (int *)realloc(arr, n * sizeof(int));
    
    printf("--- Realloc Array ---\n");
    for (int i = 5; i < n; i++) arr[i] = i * i;
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    
    manage_entity();

    return 0;
}
