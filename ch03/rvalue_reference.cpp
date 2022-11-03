#include <iostream>

int intVal()
{
    return 5; // anonymous variable: assignment requires a copy
}

int main()
{
    // int &ir = intVal();      // fails: refers to a temporary
    int const &ic = intVal();   // OK: immutable temporary
    // int *ip = &intVal();     // fails: no lvalue available

    // conclusion: it is not possible to modify the temporary returned to by intVal

    return 0;
}
