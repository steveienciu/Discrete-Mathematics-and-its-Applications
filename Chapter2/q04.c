/* determine whether functions to set of integers is one-to-one */

#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

#define N 5

bool is_one_to_one(const int func[], int size);

int main(void)
{
    bool result;
    int func[] = { 1, 2, 2, 4, 5 };

    result = is_one_to_one(func, N);

    // output result
    if (result) {
        fprintf(stdout, "\nFunction is one-to-one\n");
    }
    else {
        fprintf(stdout, "\nFunction is not one-to-one\n");
    }

    return 0;
}

bool is_one_to_one(const int func[], int size)
{
    // search for duplicates 
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i != j && func[i] == func[j]) {
                return false;
            }
        }
    }

    return true;
}
