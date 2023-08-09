/* given two m x n Boolean matrices, find their meet and join */

#include <stdio.h>
#include <stdlib.h>

#define FAILURE exit(0)

void mem_failure(void);
void input_failure(void);

int main(void)
{
    // martix where size will be allocated dymaically
    int **matrixa, **matrixb;
    // dimension of matrix
    int m, n;

    // get matrix dimensions
    fprintf(stdout, "\nEnter the dimension of the two matrices (m x n): ");
    scanf("%d %d", &m, &n);
    if (m < 2 || n < 2) {
        input_failure();
    }

    // allocate memory for matrices
    matrixa = malloc(m * sizeof(int));
    if (matrixa == NULL) {
        mem_failure();
    }
    matrixb = malloc(m * sizeof(int));
    if (matrixb == NULL) {
        free(matrixa);
        mem_failure();
    }
    for (int i = 0; i < m; ++i) {
        matrixa[i] = malloc(n * sizeof(int));
        matrixb[i] = malloc(n * sizeof(int));
        if (matrixa[i] == NULL || matrixb[i] == NULL) {
            free(matrixa);
            free(matrixb);
            mem_failure();
        }
    }

    // get inputs for matrix A
    fprintf(stdout, "\nPlease enter boolean elements of matrix A:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrixa[i][j]);
            // accept only 1's and 0's
            if (matrixa[i][j] != 0 && matrixa[i][j] != 1) {
                free(matrixa);
                free(matrixb);
                input_failure();
            }
        }
    }
    // get inputs for matrix B
    fprintf(stdout, "\nPlease enter boolean elements of matrix B:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrixb[i][j]);
            // accept only 1's and 0's
            if (matrixb[i][j] != 0 && matrixb[i][j] != 1) {
                free(matrixa);
                free(matrixb);
                input_failure();
            }
        }
    }

    // print the meet
    fprintf(stdout, "\nA and B = \n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fprintf(stdout, "%d ", matrixa[i][j] & matrixb[i][j]);
            if (j == n - 1) {
                fprintf(stdout, "\n");
            }
        }
    }
    // print the join
    fprintf(stdout, "\nA or B = \n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fprintf(stdout, "%d ", matrixa[i][j] | matrixb[i][j]);
            if (j == n - 1) {
                fprintf(stdout, "\n");
            }
        }
    }

    // deallocate memory
    free(matrixa); free(matrixb);
}

void mem_failure(void)
{
    fprintf(stderr, "\nMemory was not allocated.\n");
    FAILURE;
}

void input_failure(void)
{
    fprintf(stderr, "\nImproper input.\n");
    FAILURE;
}
