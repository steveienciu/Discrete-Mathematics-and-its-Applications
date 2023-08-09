/* given two fuzzy sets A and B, find NOT A, A OR B, A AND B */

#include <stdio.h>
#include <stdlib.h>

#define SIZEA ((int) sizeof(seta) / sizeof(seta[0]))
#define SIZEB ((int) sizeof(setb) / sizeof(setb[0]))

int main(void)
{
    float seta[] = { 0.2, 0.5, 0.6, 0.9 }, setb[] = { 0.1, 0.24, 0.56, 0.98 };

    // find NOT A
    fprintf(stdout, "\nNOT A:");
    for (int i = 0; i < SIZEA; ++i) {
        fprintf(stdout, " %0.2f", 1 - seta[i]);
    }

    // find A OR B
    fprintf(stdout, "\nA OR B:");
    for (int i = 0; i < SIZEA; ++i) {
        if (seta[i] >= setb[i]) {
            fprintf(stdout, " %0.2f", seta[i]);
        }
        else {
            fprintf(stdout, " %0.2f", setb[i]);
        }
    }

    // find A AND B
    fprintf(stdout, "\nA AND B:");
    for (int i = 0; i < SIZEA; ++i) {
        if (seta[i] >= setb[i]) {
            fprintf(stdout, " %0.2f", setb[i]);
        }
        else {
            fprintf(stdout, " %0.2f", seta[i]);
        }
    }
    fprintf(stdout, "\n");

    return 0;
}
