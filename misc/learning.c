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
    char name[10];
    scanf("Enter Name %s", name);
    printf("This is my name %s", name);
    // using prin
    char myword[] = "Hello";
    char hello[] = "hello";
    char world[] = "world";
    char combinedString[11];

    char copyMyWord[6];
    printf("EIOFJWJFE");
    // printf("%d %s", i, myword);

    for (int i = 0; i < strlen(myword); i++)
    {
        printf("EIOFJWJFE");
    }

    // printf("Before Copy \n %s", copyMyWord);
    // strcpy(myword, copyMyWord);
    // printf("After Copy \n %s", copyMyWord);

    // printf("Combined Word %s", strcat(combinedString, world));
    //  combinedString = (hello, world);

    // printf("Final Output %d %s", i, myword);

    // int *numpointer = NULL;
    // int num = 4;
    // numpointer = &num;
    // printf("\n%d", numpointer[0]);
    int num = 4;
    square(&num);
}
void square(int const *x)
{
    printf("Square of number%d", (*x) * (*x));
}
