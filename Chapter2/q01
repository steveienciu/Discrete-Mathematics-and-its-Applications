/* find ~A, A and B, A or B, and A xor B of sets A and B with n elements */

#include <stdio.h>

#define N 5

int main(void)
{
    // variables for two sets A and B
    int set1[N], set2[N];

    // create bit string
    fprintf(stdout, "\nEnter string for set A:\n");
    for (int i = 0; i < N;) {
        fscanf(stdin, "%d", &set1[i]);

        if (set1[i] == 0 || set1[i] == 1) {
            ++i;
        }
        else {
            fprintf(stdout, "Invalid bit. Please enter either a 1 or 0.\n");
        }
    }

    // create bit string
    fprintf(stdout, "\nEnter string for set B:\n");
    for (int i = 0; i < N;) {
        fscanf(stdin, "%d", &set2[i]);

        if (set2[i] == 0 || set2[i] == 1) {
            ++i;
        }
        else {
            fprintf(stdout, "Invalid bit. Please enter either a 1 or 0.\n");
        }
    }

    // print NOT A
    fprintf(stdout, "\nBit string ~A is: ");
    for (int i = 0; i < N; ++i) {
        set1[i] = set1[i] ^ 1;
        fprintf(stdout, "%d", set1[i]);
    }

    // print A AND B
    fprintf(stdout, "\nBit string A and B is: ");
    for (int i = 0; i < N; ++i) {
        fprintf(stdout, "%d", set1[i] & set2[i]);
    }

    // print A OR B
    fprintf(stdout, "\nBit string A or B is: ");
    for (int i = 0; i < N; ++i) {
        fprintf(stdout, "%d", set1[i] | set2[i]);
    }

    // print A XOR B
    fprintf(stdout, "\nBit string A xor B is: ");
    for (int i = 0; i < N; ++i) {
        fprintf(stdout, "%d", set1[i] ^ set2[i]);
    }

    fprintf(stdout, "\n");

    return 0;
}
