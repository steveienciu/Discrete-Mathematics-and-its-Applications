/* given m x k Boolean matrix A and k x n Boolean matrix B, find Boolean product A and B */

#include <stdio.h>
#include <stdlib.h>

#define FAILURE exit(0)

void mem_failure(void);
void input_failure(void);

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
    if (ak != bk || am < 2 || ak < 2 || bk < 2 || bn < 2) {
        fprintf(stderr, "\nCannot multiply the two matrices. Improper dimensions.\n");
        FAILURE;
    }

    // allocate memory for matrices A, B, and C
    matrixa = malloc(am * sizeof(int));
    if (matrixa == NULL) {
        mem_failure();
    }
    for (int i = 0; i < am; ++i) {
        matrixa[i] = malloc(ak * sizeof(int));
        if (matrixa[i] == NULL) {
            mem_failure();
        }
    }
    matrixb = malloc(bk * sizeof(int));
    if (matrixb == NULL) {
        free(matrixa);
        mem_failure();
    }
    for (int i = 0; i < bk; ++i) {
        matrixb[i] = malloc(bn * sizeof(int));
        if (matrixb[i] == NULL) {
            free(matrixa);
            mem_failure();
        }
    }
    matrixc = malloc(bn * sizeof(int));
    if (matrixc == NULL) {
        free(matrixa);
        free(matrixb);
        mem_failure();
    }
    for (int i = 0; i < bn; ++i) {
        matrixc[i] = malloc(am * sizeof(int));
        if (matrixc[i] == NULL) {
            free(matrixa);
            free(matrixb);
            mem_failure();
        }
    }

    // obtain values for matrices A and B
    fprintf(stdout, "\nPlease enter boolean elements of matrix A:\n");
    for (int i = 0; i < am; ++i) {
        for (int j = 0; j < ak; ++j) {
            scanf("%d", &matrixa[i][j]);
            // accept only 1's and 0's
            if (matrixa[i][j] != 0 && matrixa[i][j] != 1) {
                free(matrixa);
                free(matrixb);
                free(matrixc);
                input_failure();
            }
        }
    }
    fprintf(stderr, "\nPlease enter boolean elements of matrix B:\n");
    for (int i = 0; i < bk; ++i) {
        for (int j = 0; j < bn; ++j) {
            scanf("%d", &matrixb[i][j]);
            // accept only 1's and 0's
            if (matrixb[i][j] != 0 && matrixb[i][j] != 1) {
                free(matrixa);
                free(matrixb);
                free(matrixc);
                input_failure();
            }
        }
    }

    // find product matrix
    fprintf(stdout, "\nAB =\n");
    for (int i = 0; i < am; ++i) {
        for (int j = 0; j < am; ++j) {
            matrixc[i][j] = 0;
            for (int k = 0; k < bk; ++k) {
                matrixc[i][j] |= matrixa[i][k] & matrixb[k][j];
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

void input_failure(void)
{
    fprintf(stderr, "\nImproper input.\n");
    FAILURE;
}
