#include <stdio.h>
#include <stdlib.h>

int main() {
    int **pp;
    int i;

    // Allocate memory for an array of 5 int* pointers
    pp = malloc(sizeof(int*) * 5);

    // Allocate and assign values to each pointer
    for (i = 0; i < 5; i++) {
        //pp[i] = malloc(sizeof(int));  // allocate memory for each int
        *(pp+i) = malloc(sizeof(int));  // allocate memory for each int
       // *pp[i] = i * 10;              // assign value
        **(pp+i) = i * 10;              // assign value
    }

    // Print the values
    for (i = 0; i < 5; i++) {
        printf("pp[%d] points to value: %d\n", i, *pp[i]);
        printf("pp[%d] points to value: %p\n", i, *(pp+i));
    }

        printf("pp[%d] points to value: %d\n", i, **(pp+0));
    // Free allocated memory
    for (i = 0; i < 5; i++) {
        free(pp[i]);
    }
    free(pp);

    return 0;
}
