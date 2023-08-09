/* given square matrix boolean A and positive integer n, find A^n */

#include <stdio.h>
#include <stdlib.h>

#define FAILURE exit(0)

void mem_failure(void);
void input_failure(void);

int main(void)
{
    // martix where size will be allocated dymaically
    int **matrixr, **matrixa, **matrixtemp;
    // dimensions for matrix
    int x;
    // number of time to multiply
    int n;
    int counter = 1, value = 0;

    // obtain dimensions of matrix
    fprintf(stdout, "\nPlease enter dimension for the matrix: ");
    scanf("%d", &x);

    // check if proper matrix
    if (x < 1) {
        fprintf(stderr, "\nCannot multiply the two matrices. Improper dimensions.\n");
        FAILURE;
    }
    
    // obtain exponent n
    fprintf(stdout, "\nPlease enter the number of time to multiple the matrix: ");
    scanf("%d", &n);
    if (n < 0) {
        fprintf(stdout, "Improper exponent value.\n");
        FAILURE;
    }

    // allocate memory for matrices
    matrixa = malloc(x * sizeof(int));
    if (matrixa == NULL) {
        mem_failure();
    }
    for (int i = 0; i < x; ++i) {
        matrixa[i] = malloc(x * sizeof(int));
        if (matrixa[i] == NULL) {
            free(matrixa);
            mem_failure();
        }
    }
    matrixr = malloc(x * sizeof(int));
    if (matrixr == NULL) {
        free(matrixa);
        mem_failure();
    }
    for (int i = 0; i < x; ++i) {
        matrixr[i] = malloc(x * sizeof(int));
        if (matrixr[i] == NULL) {
            free(matrixa);
            free(matrixr);
            mem_failure();
        }
    }
    matrixtemp = malloc(x * sizeof(int));
    if (matrixtemp == NULL) {
        free(matrixa);
        free(matrixr);
        mem_failure();
    }
    for (int i = 0; i < x; ++i) {
        matrixtemp[i] = malloc(x * sizeof(int));
        if (matrixtemp[i] == NULL) {
            free(matrixa);
            free(matrixr);
            free(matrixtemp);
            mem_failure();
        }
    }

    // obtain values for matrix A
    fprintf(stdout, "\nPlease enter Boolean elements of matrix A:\n");
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            scanf("%d", &matrixa[i][j]);
            // accept only 1's and 0's
            if (matrixa[i][j] != 0 && matrixa[i][j] != 1) {
                free(matrixa);
                free(matrixr);
                free(matrixtemp);
                input_failure();
            }
        }
    }

    // output identity matrix
    if (n == 0) {
        fprintf(stdout, "\nA^%d =\n", n);
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < x; ++j) {
                if (i == j) {
                    fprintf(stdout, "%d ", 1);
                }
                else {
                    fprintf(stderr, "%d ", 0);
                }
                if (j == x - 1) {
                    fprintf(stdout, "\n");
                }
            }
        }
        exit(0);
    }

    // initialize result matrix to 0
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            matrixr[i][j] = 0;
        }
    }

    // find product matrix
    fprintf(stdout, "\nA^%d =\n", n);
    while (counter != n) {
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < x; ++j) {
                matrixtemp[i][j] = matrixr[i][j];
                value = 0;
                for (int k = 0; k < x; ++k) {
                    if (counter == 1) {
                        matrixtemp[i][j] |= matrixa[i][k] & matrixa[k][j];
                    }
                    else {
                        matrixr[i][j] = matrixtemp[i][k] & matrixa[k][j] | value;
                        value = matrixr[i][j];
                    }
                }
                if (counter == 1) {
                    matrixr[i][j] = matrixtemp[i][j];
                }
            }
        }
        ++counter;
    }

    // print result
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            fprintf(stdout, "%d ", matrixr[i][j]);
            if (j == x - 1) {
                fprintf(stdout, "\n");
            }
        }
    }

    // deallocate memory
    free(matrixa); free(matrixr); free(matrixtemp);

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
