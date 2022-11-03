#include <iostream>

int intVal()
{
    return 5; // anonymous variable: assignment requires a copy
}

void receive(int &value) // receive a named var
                         // compiler gets confused if there was are receive(int)
{
    std::cout << "int value parameter\n";
}

void receive(int const &value) // never called...
{
    std::cout << "int const ref parameter\n";
}

void receive(int &&value)   // receive an anon var
{
    ++value; // it stores in a variable  internally...
    std::cout << "int R-value parameter, now: " << value << '\n';
}

int main()
{
    // int &ir = intVal();      // fails: refers to a temporary
    int const &ic = intVal();   // OK: immutable temporary
    // int *ip = &intVal();     // fails: no lvalue available

    // conclusion: it is not possible to modify the temporary returned to by intVal()

    receive(18);        // temp: calls 'receive(int&&)'
    int value = 5;
    receive(value);     // lvalue: calls 'receive(int&)'
    receive(intVal());  // anon var returned: calls 'receive(int&&)'

    return 0;
}
