/*
Program: Comparison of Structure and Union Memory
Language: C

Structure Declaration:
struct DataStruct {
    int i;
    float f;
    char ch;
};

Union Declaration:
union DataUnion {
    int i;
    float f;
    char ch;
};

Assumptions:
- int = 4 bytes
- float = 4 bytes
- char = 1 byte

1) Memory occupied by DataStruct:

   In a structure, each member is stored in a separate memory location.

   int i   -> 4 bytes
   float f -> 4 bytes
   char ch -> 1 byte

   Total memory = 4 + 4 + 1 = 9 bytes

   (Note: Padding may increase size in some systems, but logically it is 9 bytes.)

2) Memory occupied by DataUnion:

   In a union, all members share the same memory location.
   The size of a union is equal to the size of its largest member.

   Largest member size:
   int or float -> 4 bytes

   Memory occupied by DataUnion = 4 bytes

3) Why memory differs between structure and union:

   Structure:
   - Each member has its own memory.
   - Total memory is the sum of all member sizes.

   Union:
   - All members share the same memory.
   - Only memory equal to the largest member is allocated.

   Therefore, a union uses less memory than a structure.

4) If a DataUnion variable stores i = 50 and then f = 2.5:

   When f is assigned, it overwrites the memory shared by the union.
   Hence, the previously stored value of i (50) is lost and becomes invalid.
*/

#include <stdio.h>

struct DataStruct {
    int i;
    float f;
    char ch;
};

union DataUnion {
    int i;
    float f;
    char ch;
};

int main() {
    union DataUnion d;
    d.i = 50;
    d.f = 2.5;

    printf("Structure vs Union memory comparison explained in comments.\n");
    return 0;
}
