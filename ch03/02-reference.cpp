/*!
 * \file reference.cpp
 * \brief Illustrate the usage of references.
 */
#include <iostream>

void increase(int *valp) // expects a pointer
{
    std::cout << "Passed as pointer..." << std::endl;
    *valp += 5;
}

void increase(int &valr) // same effect of the above function
{
    std::cout << "Passed as reference..." << std::endl;
    valr += 5;
}

int main()
{
    int val = 5;
    int &ref = val; // ref is just an alias for val.

    val++;
    ref++;

    std::cout << "val = " << val << "\n"
                 "ref = " << ref << '\n';

    increase(&val); // passing the address of val: calls increase(int*)
    std::cout << "val = " << val << std::endl;

    increase(val); // passing val as reference: calls increase(int&)...
                   // (suggests that a copy is passed)
    std::cout << "val = " << val << std::endl;

    return 0;
}
