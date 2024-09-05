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

    int num;
    char name[10];

    scanf("%d %s", &num, name);
    printf("This is my name %d %s", num, name);
}
