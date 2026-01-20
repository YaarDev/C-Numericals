/*
Program: Memory Calculation for Student Structure
Language: C

Structure:
struct Student {
    int roll;
    char name[20];
    float marks;
};

1) Memory occupied by one Student structure:
   int roll        -> 4 bytes
   char name[20]   -> 20 bytes
   float marks     -> 4 bytes
   Total           -> 28 bytes

2) Memory required for array of 50 students:
   28 × 50 = 1400 bytes

3) Address of marks of the 10th student:
   Base address = 4000
   Size of one structure = 28 bytes
   Offset of marks = 4 + 20 = 24 bytes

   Address = 4000 + (9 × 28) + 24
           = 4276
*/

#include <stdio.h>

struct Student {
    int roll;
    char name[20];
    float marks;
};

int main() {
    printf("Student structure memory numerical (see comments).\n");
    return 0;
}
