#include <stdio.h>

// Function Definitions

// Performs the bitwise AND operation between two integers.
// Returns the result of a & b.
int getSizeofBinary(int a)
{
    int aCopy = a;
    int arrSize = 0;
    while (aCopy /= 2)
    {
        arrSize++;
    }
    arrSize++;

    printf("New arr size %d \n ", arrSize);
    return arrSize;
}
int *convertBinary(int a)
{
    int arrSize = getSizeofBinary(a);
    int binary[arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        // 1 1 0 0
        // 12 / 2 =
        binary[i] = a % 2;
        a /= 2;
    }

    int j = 0;
    int finalBinary[arrSize];
    for (int i = arrSize; i > -1; i--)
    {
        // Must reverse
        finalBinary[j] = binary[i];
        printf("%d ", finalBinary[j]);
    }
    printf("\n");

    return finalBinary;
}
int andOperation(int a, int b)
{
    return a & b;
    return 0;
}

// Performs the bitwise OR operation between two integers.
// Returns the result of a | b.
int orOperation(int a, int b)
{
    return a | b;
    return 0;
}

// Performs the bitwise XOR operation between two integers.
// Returns the result of a ^ b.
int xorOperation(int a, int b)
{
    return a ^ b;
    return 0;
}

// Performs the bitwise NOT operation on an integer.
// Returns the result of ~a.
int notOperation(int a)
{
    return ~a;
    return 0;
}

// Shifts the bits of 'num' to the left by 'shift' positions.
// Returns the result of num << shift.
int leftShift(int num, int shift)
{
    return num << shift;
}

// Shifts the bits of 'num' to the right by 'shift' positions.
// Returns the result of num >> shift.
int rightShift(int num, int shift)
{
    return num >> shift;
    return 0;
}

// Sets the bit at 'position' in 'num' to 1.
// Returns the modified number.
int setBit(int num, int position)
{
    // num++;
    // if (position == 1)
    // {
    //     return num;
    // }
    // else
    // {
    //     return num << (position - 1);
    // }
    return num | (1 << position);
}

// Clears the bit at 'position' in 'num' (sets it to 0).
// Returns the modified number.
int clearBit(int num, int position)
{
    return num--;
}

// Toggles the bit at 'position' in 'num'.
// Returns the modified number.
int toggleBit(int num, int position)
{
    return (num ^ (1 << (position)));
}

// Packs two 4-bit numbers 'a' and 'b' into a single 8-bit number.
// 'a' occupies the higher 4 bits, and 'b' occupies the lower 4 bits.
// Returns the packed 8-bit number.
int packBits(int a, int b)
{
    return (a << 4) + b;
}

// Unpacks an 8-bit number 'packed' into two 4-bit numbers.
// Stores the higher 4 bits in '*a' and the lower 4 bits in '*b'.
void unpackBits(int packed, int *a, int *b)
{
    int frontBits[4];
    int backBits[4];

    int packedCopy = packed;
    int startingFrontBitMask = 128; // 1000
    int endingBackBitMask = 8;      // 1000

    // printf("Packed Value: %d \n", packed);

    for (int i = 0; i < 4; i++)
    {
        // printf("%d \n", (packed & startingBitMask)); // 128
        printf("VALUE: %d \n ", packed & startingFrontBitMask);
        frontBits[i] = packed & startingFrontBitMask ? 1 : 0;
        backBits[i] = packed & endingBackBitMask ? 1 : 0;
        printf("Front: %d ", (frontBits[i]));
        printf("Back: %d \n", (backBits[i]));
        startingFrontBitMask = startingFrontBitMask >> 1;
        endingBackBitMask = endingBackBitMask >> 1;
    }
    *a = *frontBits;
    *b = *backBits;
}

// Performs a circular left shift on 'num' by 'shift' positions.
// Returns the result of the circular left shift.
int circularLeftShift(int num, int shift)
{

    // num = 110; // 0101 1110 (110)= 1110 0101 (229)
    // shift = 4;
    int mask = 240;              // 1111
    int maskedBits = mask & num; // 96
    num = num << shift;
    num = (maskedBits >> shift) | num;
    printf("\n%d\n", num);

    // Mask to keep the result within 8 bits
    return num & 255;

    // NUM (110) & 240 -> 96 (1010)
    // x << SHIFT (Create space right (all zeros)
    // x = y >> 4 | x (shift them to the right and or with the first most 4 bits)
}

// Performs a circular right shift on 'num' by 'shift' positions.
// Returns the result of the circular right shift.
int circularRightShift(int num, int shift)
{

    // num = 110; // 0101 1110 (110)= 1110 0101 (229)
    // shift = 4;
    int mask = 15;               // 1111
    int maskedBits = mask & num; // 96
    num = num >> shift;
    num = (maskedBits << shift) | num;
    printf("\n%d\n", num);

    // Mask to keep the result within 8 bits
    return num & 255;

    return 0;
}

int main()
{
    int a = 8; // Example value
    int b = 2; // Example value

    // Perform and display results for each bitwise operation
    // printf("AND Operation: %d\n", andOperation(a, b));
    // printf("OR Operation: %d\n", orOperation(a, b));
    // printf("XOR Operation: %d\n", xorOperation(a, b));
    // printf("NOT Operation: %d\n", notOperation(a));

    int shift = 2;
    // printf("Left Shift: %d\n", leftShift(a, shift));
    // printf("Right Shift: %d\n", rightShift(a, shift));

    // Bit manipulation examples
    int position = 2;
    // printf("Set Bit: %d\n", setBit(a, position));
    // printf("Clear Bit: %d\n", clearBit(a, position));
    // 12 2
    // printf("Toggle Bit: %d\n", toggleBit(a, position));

    // // Packing and unpacking
    int packed = packBits(a, b);
    // printf("Packed Value: %d\n", packed);
    int unpackedA, unpackedB = 0;
    unpackBits(packed, &unpackedA, &unpackedB);

    // Circular shifts
    // printf("Circular Left Shift: %d\n", circularLeftShift(a, shift));
    // printf("Circular Right Shift: %d\n", circularRightShift(a, shift));

    return 0;
}