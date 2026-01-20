/*
Program: Memory and Behavior of Union in C
Language: C

Union Declaration:
union Data {
    int i;
    float f;
    char ch;
};

Assumptions:
- int = 4 bytes
- float = 4 bytes
- char = 1 byte

1) Memory occupied by union Data:

   In a union, all members share the same memory location.
   Therefore, the size of the union is equal to the size of
   its largest data member.

   Sizes:
   int   -> 4 bytes
   float -> 4 bytes
   char  -> 1 byte

   Largest member size = 4 bytes

   Memory occupied by union Data = 4 bytes

2) If i = 100 and then f = 3.14 are assigned in the same union variable:

   When a new value is assigned to one member of a union,
   it overwrites the memory shared by all members.

   Therefore, after assigning f = 3.14,
   the previous value of i (100) is lost and becomes invalid.

3) Why union saves memory compared to structures:

   In a structure, each member has its own separate memory,
   so total memory is the sum of all member sizes.

   In a union, all members share the same memory,
   so only memory equal to the largest member is allocated.

   Hence, unions save memory when only one member is used at a time.
*/

#include <stdio.h>

union Data {
    int i;
    float f;
    char ch;
};

int main() {
    union Data d;
    d.i = 100;
    d.f = 3.14;

    printf("Union behavior explained in comments.\n");
    return 0;
}
