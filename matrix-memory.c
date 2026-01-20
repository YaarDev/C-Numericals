/*
Program: Memory and Address Calculation for 2D Array
Language: C

Array Declaration:
int matrix[5][6];

Assumptions:
- Size of int = 4 bytes
- Row-major order is used
- Base address = 2000

1) Total memory required:
   Total elements = 5 × 6 = 30
   Memory required = 30 × 4 = 120 bytes

2) Address of matrix[3][4]:
   Formula (row-major):
   Address = Base + ((i × number_of_columns + j) × size_of_element)

   Address = 2000 + ((3 × 6 + 4) × 4)
           = 2000 + (22 × 4)
           = 2088

3) Address difference between matrix[1][2] and matrix[4][5]:

   Address of matrix[1][2]:
   = 2000 + ((1 × 6 + 2) × 4)
   = 2032

   Address of matrix[4][5]:
   = 2000 + ((4 × 6 + 5) × 4)
   = 2116

   Address difference = 2116 − 2032 = 84 bytes
*/

#include <stdio.h>

int main() {
    printf("2D array memory numerical solved. See comments for details.\n");
    return 0;
}
