/*
Program: Memory Calculation using enum, union, and structure
Language: C

Enum Declaration:
enum Type { INT, FLOAT, CHAR };

Union Declaration:
union Value {
    int i;
    float f;
    char ch;
};

Structure Declaration:
struct Variable {
    enum Type t;
    union Value v;
};

Assumptions:
- enum = 4 bytes
- int = 4 bytes
- float = 4 bytes
- char = 1 byte

1) Memory required for one Variable structure:

   enum Type t:
   - enum occupies 4 bytes

   union Value v:
   - All members share the same memory
   - Sizes:
       int   -> 4 bytes
       float -> 4 bytes
       char  -> 1 byte
   - Largest member size = 4 bytes

   Memory occupied by union Value = 4 bytes

   Total memory for one Variable:
   = 4 (enum) + 4 (union)
   = 8 bytes

2) Memory required for 50 Variable structures:

   Memory for one Variable = 8 bytes

   Total memory = 8 × 50
                = 400 bytes

3) How enum and union work together when t = FLOAT and v.f = 3.14:

   - The union stores only one value at a time.
   - When v.f = 3.14 is assigned, the float member occupies the union memory.
   - The enum variable t is set to FLOAT to indicate the type of data
     currently stored in the union.

   Thus:
   - union Value stores the actual data (3.14)
   - enum Type identifies which member of the union is valid

   This combination allows efficient memory usage while still keeping
   track of the data type.
*/

#include <stdio.h>

enum Type { INT, FLOAT, CHAR };

union Value {
    int i;
    float f;
    char ch;
};

struct Variable {
    enum Type t;
    union Value v;
};

int main() {
    struct Variable var;
    var.t = FLOAT;
    var.v.f = 3.14;

    printf("Enum and Union working together explained in comments.\n");
    return 0;
}
