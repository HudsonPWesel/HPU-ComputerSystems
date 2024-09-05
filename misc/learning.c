#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h> // Include the header for printf

// Function prototype
void square(int const *x);

// Function definition

int main(int argc, char *argv[])
{
    // Everything I've learned about so far

    /* Using scanf & printf */
    // scanf("Enter Name %s", name);
    // printf("This is my name %s", name);

    // int num;
    // char name[10];

    // scanf("%d %s", &num, name);
    // printf("This is my name %d %s", num, name);

    /* Using Enums */
    // enum color
    // {
    //     B,
    //     R,
    //     G
    // };

    // enum color NEWCOLOR = B; // this is actually an int

    // enum direction
    // {
    //     L = 10,
    //     U = 20,
    //     R = 30,
    //     D = 40,
    // };
    // enum direction LEFT = L;

    /* Using Bitwise */
    //    &, |, ^, ~, <<, >>

    /* Cast & sizeof */
    // (type) (var)
    // sizeof(varname) --> Number of bytes
    /* Arrays*/
    int numValues[10] = {0, 1, 2, 3, 9, 10};
    int arrSize = 4;
    int newArray[arrSize];
}
