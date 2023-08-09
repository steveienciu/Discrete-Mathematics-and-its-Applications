/* given universal set and sets A and B, find A and B, A or B, A - B, and A + B */

#include <stdio.h>
#include <stdlib.h>

// define size of each set
#define SIZEA ((int) sizeof(seta) / sizeof(seta[0]))
#define SIZEB ((int) sizeof(setb) / sizeof(setb[0]))
#define SIZEU ((int) sizeof(universal) / sizeof(Universal[0]))

int main(void) 
{
    int universal[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, seta[] = { 1, 2, 3 }, setb[] = { 3, 7, 9 };
    int counter = 0, slarge, ssmall;

    // subsets need to be smaller or equal to universal set
    if (seta > universal || setb > universal) {
        fprintf(stderr, "\nInvalid subsets A and B\n");
        exit(0);
    }

    // find the AND of two sets
    fprintf(stdout, "\nA and B:");
    for (int i = 0; i < SIZEA; ++i) {
        for (int j = 0; j < SIZEB; ++j) {
            if (seta[i] == setb[j]) {
                fprintf(stdout, " %d", seta[i]);
                break;
            }
        }
    }

    // find the OR of two sets
    fprintf(stdout, "\nA or B:");
    for (int i = 0; i < SIZEA; ++i) {
        fprintf(stdout, " %d", seta[i]);
    }
    for (int i = 0; i < SIZEB; ++i) {
        for (int j = 0; j < SIZEA; ++j) {
            if (setb[i] == seta[j]) {
                counter = 0;
                break;
            }
            else {
                ++counter;
            }

            if (counter == SIZEA) {
                fprintf(stdout, " %d", setb[i]);
                counter = 0;
            }
        }
    }

    // find the DIFFERENCE of two sets
    fprintf(stdout, "\nA - B:");
    for (int i = 0; i < SIZEA; ++i) {
        for (int j = 0; j < SIZEB; ++j) {
            if (seta[i] == setb[j]) {
                counter = 0;
                break;
            }
            else {
                ++counter;
            }

            if (counter == SIZEB) {
                fprintf(stdout, " %d", seta[i]);
                counter = 0;
            }
        }
    }

    // find the SUM of two sets
    fprintf(stdout, "\nA + B:");
    if (SIZEA >= SIZEB) {
        slarge  = SIZEA;
        ssmall = SIZEB;
    }
    else {
        slarge = SIZEB;
        ssmall = SIZEA;
    }
    for (int i = 0; i < slarge; ++i) {
        if (i < ssmall) {
            fprintf(stdout, " %d", seta[i] + setb[i]);
        }
        else if (i >= ssmall && ssmall == SIZEB) {
            fprintf(stdout, " %d", seta[i]);
        }
        else if (i >= ssmall && ssmall == SIZEA) {
            fprintf(stdout, " %d", setb[i]);
        }
    }
    fprintf(stdout, "\n");

    return 0;
}
