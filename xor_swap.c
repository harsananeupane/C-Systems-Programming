/*
 * XOR Integer Swap
 * Author: Harsana Neupane
 *
 * Demonstrates dynamic memory allocation and bitwise XOR
 * operations by swapping two integers without a temporary variable.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *int_ptr;

    int_ptr = malloc(2 * sizeof(int));

    if (int_ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter first integer: ");
    scanf("%d", &int_ptr[0]);

    printf("Enter second integer: ");
    scanf("%d", &int_ptr[1]);

    printf("Original values: 1st = %d, 2nd = %d\n",
           int_ptr[0], int_ptr[1]);

    int_ptr[0] = int_ptr[0] ^ int_ptr[1];
    int_ptr[1] = int_ptr[0] ^ int_ptr[1];
    int_ptr[0] = int_ptr[0] ^ int_ptr[1];

    printf("Swapped values: 1st = %d, 2nd = %d\n",
           int_ptr[0], int_ptr[1]);

    free(int_ptr);

    return 0;
}
