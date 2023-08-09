/* give m x k matrix A and k x n matrix B, find AB */

#include <stdio.h>
#include <stdlib.h>

#define FAILURE exit(0)

void mem_failure(void);

int main(void)
{
    // martix where size will be allocated dymaically
    int **matrixc, **matrixa, **matrixb;
    // different dimensions for matrices 
    int am, ak, bk, bn;

    // obtain dimensions of matrices
    fprintf(stdout, "\nPlease enter dimensions for matrix A (m x k): ");
    scanf("%d %d", &am, &ak);
    fprintf(stdout, "Please enter dimensions for matrix B (k x n): ");
    scanf("%d %d", &bk, &bn);

    // check if able to multiply the two
    if (ak != bk || am < 1 || ak < 1 || bk < 1 || bn < 1) {
        fprintf(stderr, "\nCannot multiply the two matrices. Improper dimensions.\n");
        FAILURE;
    }

    // allocate memory for matrices A, B, and C
    matrixa = malloc(am * sizeof(int));
    for (int i = 0; i < am; ++i) {
        matrixa[i] = malloc(ak * sizeof(int));
    }
    if (matrixa == NULL) {
        mem_failure();
    }
    matrixb = malloc(bk * sizeof(int));
    for (int i = 0; i < bk; ++i) {
        matrixb[i] = malloc(bn * sizeof(int));
    }
    if (matrixb == NULL) {
        free(matrixa);
        mem_failure();
    }
    matrixc = malloc(bn * sizeof(int));
    for (int i = 0; i < bn; ++i) {
        matrixc[i] = malloc(am * sizeof(int));
    }
    if (matrixc == NULL) {
        free(matrixa);
        free(matrixb);
        mem_failure();
    }


    // obtain values for matrices A and B
    fprintf(stdout, "\nPlease enter elements of matrix A:\n");
    for (int i = 0; i < am; ++i) {
        for (int j = 0; j < ak; ++j) {
            scanf("%d", &matrixa[i][j]);
        }
    }
    fprintf(stderr, "\nPlease enter elements of matrix B:\n");
    for (int i = 0; i < bk; ++i) {
        for (int j = 0; j < bn; ++j) {
            scanf("%d", &matrixb[i][j]);
        }
    }

    // find product matrix
    fprintf(stdout, "\nAB =\n");
    for (int i = 0; i < am; ++i) {
        for (int j = 0; j < am; ++j) {
            matrixc[i][j] = 0;
            for (int k = 0; k < bk; ++k) {
                matrixc[i][j] += matrixa[i][k] * matrixb[k][j];
            }
            fprintf(stdout, "%d ", matrixc[i][j]);
            if (j == am - 1) {
                fprintf(stdout, "\n");
            }
        }
    }

    // deallocate memory
    free(matrixa); free(matrixb); free(matrixc);

    return 0;
}

void mem_failure(void)
{
    fprintf(stderr, "\nMemory was not allocated.\n");
    FAILURE;
}
