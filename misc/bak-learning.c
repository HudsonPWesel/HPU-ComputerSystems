#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Everything I've learned about so far
    int i;
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

    printf("Before Copy \n %s", copyMyWord);
    strcpy(myword, copyMyWord);
    printf("After Copy \n", copyMyWord);

    printf("Combined Word %s", strcat(hello, world));
    // combinedString = (hello, world);

    printf("Final Output %d %s", i, myword);
}