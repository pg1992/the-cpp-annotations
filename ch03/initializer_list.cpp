#include <cstdio>
#include <iostream>
#include <initializer_list>

void func(std::initializer_list<int> vals)
{
    std::initializer_list<int>::const_iterator val;
    for (val = vals.begin() ; val != vals.end() ; val++)
        std::cout << "val = " << *val << '\n';
}

int main()
{
    do {
        std::cout << "\033[2J\033[H";
        func({10, 200, 3000});
    } while (getchar() != 'q');

    return 0;
}
