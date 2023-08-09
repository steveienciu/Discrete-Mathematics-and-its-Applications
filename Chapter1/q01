/* find truth values of bitwise operations on two propositions */

#include <stdio.h>

int main(void)
{
    // variables for the two propositions
    unsigned short p, q;

    // get input from while loop incase user inputs something other than 1 or 0
    while (1) {
        fprintf(stdout, "\nPlease enter truth values for p and q, respectively: ");
        scanf("%hu%hu", &p, &q);

        // check to see if 0 ir 1 was inputted
        if ((p == 0 || p == 1) && ( q == 0 || q == 1)) {
            break;
        }
    }

    // output the results 
    fprintf(stdout, "\nThe conjunciton of the two propositions is %hu\n", p & q);
    fprintf(stdout, "The disjunction of the two propositions is %hu\n", p | q);
    fprintf(stdout, "The exclusive or of the two propositions is %hu\n", p ^ q);
    fprintf(stdout, "The conditional statement of the two propositions is %hu\n", (p & q) | !p);
    fprintf(stdout, "The biconditional statement of the two propositions is %hu\n", !(p ^ q));

    return 0;
}
