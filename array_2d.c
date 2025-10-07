#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;
    int rows = 3, cols = 4;

    // Allocate memory for row pointers
    arr = malloc(rows * sizeof(int *));
    if (arr == NULL) {
        perror("Memory allocation failed for rows");
        return 1;
    }

    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            perror("Memory allocation failed for columns");
            return 1;
        }
    }

    // Assign values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j;
        }
    }

    // Print values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", arr[i][j]);
//            printf("%3d ", *(*(arr+i)+j));
        }
            printf("%p ", arr+i);
            printf("%p ", *(arr+i));
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
