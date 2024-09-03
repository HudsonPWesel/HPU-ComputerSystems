#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%d %s", argc, argv[1]);
    // Scanf requires format specifier just like with printf to tell our C program how the inputted value should be handled (not just always as a char)
}