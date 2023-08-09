/* find bitwise AND, OR, and XOR of two bit strings */

#include <stdio.h>
#include <string.h>

#define N 8

// function to properly take inputs
int bit_string_input(char *input, int n);

int main(void) 
{
    // variables to store the byte string
    char byte1[N + 1], byte2[N + 1], resultAND[N + 1], resultOR[N + 1], resultXOR[N + 1];
    // variables used to manipulate the bits
    unsigned short bit1, bit2;

    fprintf(stdout, "\nPlease enter the value of the first byte:  ");
    bit_string_input(byte1, N + 1);
    fprintf(stdout, "Please enter the value of the second byte: ");
    bit_string_input(byte2, N + 1);

    // check if both strings contain 8 bits
    if (strlen(byte1) != N && strlen(byte2) != N) {
        fprintf(stderr, "\nInvalid byte length\n");
        return 0;
    }

    // loop to manipulate the bits
    for (int i = 0; i < N; ++i) {
        // turn char to int
        bit1 = byte1[i] - 48;
        bit2 = byte2[i] - 48;

        // turn int back to char
        resultAND[i] = (bit1 & bit2) + '0';
        resultOR[i] = (bit1 | bit2) + '0';
        resultXOR[i] = (bit1 ^ bit2) + '0';
    }
    resultAND[N] = 0; resultOR[N] = 0; resultXOR[N] = 0;

    // output the results 
    fprintf(stdout, "\nThe bitwise AND of the two bytes are: ");
    puts(resultAND);
    fprintf(stdout, "The bitwise OR of the two bytes are: ");
    puts(resultOR);
    fprintf(stdout, "The bitwise XOR of the two bytes are: ");
    puts(resultXOR);

    return 0;
}

int bit_string_input(char *input, int n)
{
    char ch;
    int counter = 0;

    while (counter < n) {
        ch = getchar();
        if (ch == '\n') {
            break;
        }
        input[counter++] = ch;
    }

    input[counter] = 0;
}
