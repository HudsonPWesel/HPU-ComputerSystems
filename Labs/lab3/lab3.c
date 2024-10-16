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
    return 255 & ~a;
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
    // if (position == 1) // { //     return num; // }
    // else // { //     return num << (position - 1); // }
    return num | (1 << position);
}

// Clears the bit at 'position' in 'num' (sets it to 0).
// Returns the modified number.
int clearBit(int num, int position)
{
    return num & ~(1 << position);
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
    return (a << 4) | (b & 0xF);
}

// Unpacks an 8-bit number 'packed' into two 4-bit numbers.
// Stores the higher 4 bits in '*a' and the lower 4 bits in '*b'.
void unpackBits(int packed, int *a, int *b)
{
    int frontBits[4];
    int backBits[4];

    int packedCopy = packed;
    int startingFrontBitMask = 128;
    int endingBackBitMask = 8;

    for (int i = 0; i < 4; i++)

    {
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
    int size = sizeof(num) * 8;
    int b = num << shift;
    int c = num >> (size - shift);
    printf("%d", b | c);

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

    int size = sizeof(num) * 8;
    int b = num >> shift;
    int c = num << (size - shift);
    printf("%d", b | c);

    return num & 255;
    // int masks[] = {128, 192, 224, 240};
    // int mask = masks[shift - 1];

    // int maskedBits = mask & num;
    // num = num << shift;
    // num = (maskedBits >> (8 - shift)) | num;

    // return num & 255;
}

int main()
{
    int a = 8; // Example value
    int b = 2; // Example value

    printf("OR Operation: %d\n", orOperation(a, b));
    printf("XOR Operation: %d\n", xorOperation(a, b));
    printf("NOT Operation: %d\n", notOperation(a));

    int shift = 2;
    printf("Left Shift: %d\n", leftShift(a, shift));
    printf("Right Shift: %d\n", rightShift(a, shift));

    // Bit manipulation examples
    int position = 2;
    printf("Set Bit: %d\n", setBit(a, position));
    printf("Clear Bit: %d\n", clearBit(a, position));
    printf("Toggle Bit: %d\n", toggleBit(a, position));

    // Packing and unpacking
    int packed = packBits(a, b);
    printf("Packed Value: %d\n", packed);
    int unpackedA, unpackedB = 0;
    unpackBits(packed, &unpackedA, &unpackedB);

    // Circular shifts
    printf("Circular Left Shift: %d\n", circularLeftShift(a, shift));
    printf("Circular Right Shift: %d\n", circularRightShift(a, shift));

    return 0;
}

/*
Lab Questions:
1. What is the difference between the bitwise AND (&) and the logical AND (&&)
operators in C?
- One returns a boolean value and one returns a logical value.
2. If you perform the bitwise OR operation (|) on the numbers 5 (0101 in binary) and 3
(0011 in binary), what is the result? Explain how you arrived at the answer.
0101
0011
(0 | 0) = 0
(1 | 0) = 1
(0 | 1) = 1
(1 | 1) = 1
0111 = 7

3. What does the bitwise NOT (~) operation do to the binary number 00001111?
Flip bits (11110000)
4. What would be the result of performing an XOR (^) operation on any number with
itself, like a ^ a? Why? It will always be 0 because wherever there is a 1 in the first number there is a 1 in the second number which produces a zero. all else are zeros.
0000 1111
0000 1111

5. If you have an 8-bit number 11010010, how can you clear the third bit (counting from
the right, zero-indexed) using a bitwise operation?
num & ~(1 << position);
(1 << n) generates a binary number with a 1 at the nth position and zeros elsewhere. The bitwise NOT operator (~) flips all the bits, effectively creating a mask with a 1 at the nth position and zeros elsewhere. Then, the bitwise AND used to AND the original number with the mask, clearing the nth bit.
-- given the value 6 and we want to clear the third bit --

0000 0001 (1)
0000 0100 (1 << 2)
1111 1011 (NOT)

    0000 1100 (6)
AND 1111 1011
    0000 1000 (4) Bit cleared!

6. Why is the bitwise OR operation useful when you want to set specific bits in a
number without changing the others?
Because you can use it as a mask to filter for specific bits.

7. Can you explain in your own words what a “bit mask” is and how it can be used in
combination with bitwise operations?*/

// A bit mask a binary value with specific bits turned on and when AND'd with a number, will mask to see if those specific bits are turned on in the specific number
