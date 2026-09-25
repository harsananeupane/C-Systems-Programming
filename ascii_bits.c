/*
 * ASCII Bits & Bytes
 * Author: Harsana Neupane
 * Systems Programming
 */

#include <stdio.h>

int main(void)
{
    unsigned char character;
    int temp;
    int i;

    printf("Enter an ASCII character: ");
    scanf("%c", &character);

    printf("The ASCII value of %c is:\n", character);
    printf("\tdec - %d\n", character);
    printf("\thex - %X\n", character);
    printf("\tbin -\n\t");

    for (i = 7; i >= 0; i--)
    {
        temp = (character >> i) & 1;
        printf("%d", temp);
    }

    printf("\n");

    return 0;
}
