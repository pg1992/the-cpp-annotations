/*!
 * \file reference.cpp
 * \brief Illustrate the usage of references.
 */
#include <iostream>

int main()
{
    int val = 5;
    int &ref = val; // ref is just an alias for val.

    val++;
    ref++;

    std::cout << "val = " << val << "\n"
                 "ref = " << ref << '\n';

    return 0;
}
