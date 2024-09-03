#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // C offers logical and shift operattors (operating on bits)
    printf("%d", 128 & 6);
    printf("%d", 128 | 6);
    printf("%d", 128 >> 6);
    printf("\n %d", 128 << 3);
}