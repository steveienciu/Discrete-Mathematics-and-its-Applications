/* given square matrix, determine whether its symmetric */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FAILURE exit(0)

void mem_failure(void);

int main(void)
{
    // martix where size will be allocated dymaically
    int **matrixa;
    // dimensions for matrix
    int x;
    // whether matrix symmetric
    bool result = true;

    // obtain dimensions of matrix
    fprintf(stdout, "\nPlease enter dimension for the matrix: ");
    scanf("%d", &x);

    // check if proper matrix
    if (x < 1) {
        fprintf(stderr, "\nCannot multiply the two matrices. Improper dimensions.\n");
        FAILURE;
    }

    // allocate memory for matrice
    matrixa = malloc(x * sizeof(int));
    for (int i = 0; i < x; ++i) {
        matrixa[i] = malloc(x * sizeof(int));
    }
    if (matrixa == NULL) {
        mem_failure();
    }

    // obtain values for matrix A
    fprintf(stdout, "\nPlease enter elements of matrix A:\n");
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            scanf("%d", &matrixa[i][j]);
        }
    }

    // get transpose of matrix A 
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            if (matrixa[i][j] != matrixa[j][i]) {
                result = false;
                break;
            }
        }
        if (!result) {
            break;
        }
    }

    // print result
    if (!result) {
        fprintf(stdout, "\nMatrix is not symmetric.\n");
    }
    else {
        fprintf(stdout, "\nMatrix is symmetric.\n");
    }

    // deallocate memory
    free(matrixa);

    return 0;
}

void mem_failure(void)
{
    fprintf(stderr, "\nMemory was not allocated.\n");
    FAILURE;
}
