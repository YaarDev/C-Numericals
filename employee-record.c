/*
Program: Employee Record Memory and Address Calculation
Language: C

Enum Declaration:
enum JobType { Manager, Developer, Tester };

Union Declaration:
union Salary {
    int basic;
    float net_salary;
};

Structure Declaration:
struct Employee {
    int id;
    char name[20];
    enum JobType job;
    union Salary sal;
    float performance[1][12];   // 1 year, 12 months
};

Assumptions:
- int   = 4 bytes
- char  = 1 byte
- float = 4 bytes
- enum  = 4 bytes
- Padding is ignored

--------------------------------------------------
1) Memory required for one Employee record:

   int id              -> 4 bytes
   char name[20]       -> 20 bytes
   enum JobType job    -> 4 bytes

   union Salary sal:
     int basic          -> 4 bytes
     float net_salary   -> 4 bytes
     Largest member     -> 4 bytes
     Union size         -> 4 bytes

   float performance[1][12]:
     Total elements = 1 × 12 = 12
     Memory = 12 × 4 = 48 bytes

   Total memory for one Employee:
   = 4 + 20 + 4 + 4 + 48
   = 80 bytes

--------------------------------------------------
2) Memory required for 50 Employee records:

   Memory for one Employee = 80 bytes

   Total memory = 80 × 50
                = 4000 bytes

--------------------------------------------------
3) Address of score of the 7th month in performance array:

   Base address of performance = 5000
   performance is a 2D array [1][12]
   Stored in row-major order

   Index of 7th month = 6   (0-based indexing)
   Size of float = 4 bytes

   Address = 5000 + (6 × 4)
           = 5000 + 24
           = 5024

--------------------------------------------------
4) Union Behavior:

   When basic = 50000 is assigned, the union stores the integer value.
   When net_salary = 55000.50 is assigned afterward, it overwrites
   the same memory location.

   Therefore, the previously stored value of basic is lost and becomes invalid.

--------------------------------------------------
5) Enum Behavior:

   enum JobType values are assigned starting from 0 by default:
     Manager   = 0
     Developer = 1
     Tester    = 2

   If job is set to Tester, the integer value stored in memory is 2.
*/

#include <stdio.h>

enum JobType { Manager, Developer, Tester };

union Salary {
    int basic;
    float net_salary;
};

struct Employee {
    int id;
    char name[20];
    enum JobType job;
    union Salary sal;
    float performance[1][12];
};

int main() {
    struct Employee emp;
    emp.job = Tester;
    emp.sal.basic = 50000;
    emp.sal.net_salary = 55000.50;

    printf("Employee record numerical solved. See comments for details.\n");
    return 0;
}
