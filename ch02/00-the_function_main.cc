#include <iostream>

// This is the preferred way to access environment variables in C++.
// The third argument (char **envp) is not defined in the C++ standard.
extern char **environ;

// C++ allows int main() without arguments or...
int main(int argc, char **argv)
{
    // void main() is prohibited...

    std::cout << "Environment variables:" << std::endl;
    for (char **cur = environ ; *cur ; cur++)
        std::cout << *cur << std::endl;

    std::cout << "================================================================================" << std::endl;
    std::cout << "Arguments:" << std::endl;
    for (char **cur = argv ; *cur ; cur++)
        std::cout << *cur << std::endl;

    return 0; // You can ommit the 'return 0;' but you must return an int.
              // This means you cannot use return; without an integer expression.
}
