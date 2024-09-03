#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int nums[5] = {1, 2, 3, 4, 5};
    int matrix[2][2] = {[0][0] = 1};
    char word[5] = "WORD";
    char copyword[5];

    char part1[12] = "PART1";
    char part2[] = "PART2";

    printf("%s \n", part1);

    // Basic for-loop
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        printf("Number: %d\n", nums[i]);
    }

    // /*Using string functions */
    // strlen
    for (int i = 0; i < strlen(word); i++)
    {

        printf("Word: %c ", word[i]);
        printf("%d \n", i);
    }

    // strcpy
    printf("FIRST %s\n", copyword);
    strcpy(copyword, word);
    printf("COPIED WORD: %s", copyword);

    // strcat Be careful to make sure that array 1 can fit into array 2
    printf("Concated word %s", strcat(part1, part2));
}