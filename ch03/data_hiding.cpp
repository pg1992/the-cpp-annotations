#include <iostream>
#include <cstring>

struct Person {
    private:
        char d_name[80];
        char d_address[80];
    public:
        void setName(char const *n);
        void setAddress(char const *a);
        void print();
        char const *name();
        char const *address();
};

void Person::setName(char const *n)
{
    strncpy(d_name, n, 79);
    d_name[79] = 0;
}

void Person::setAddress(char const *a)
{
    strncpy(d_address, a, 79);
    d_address[79] = 0;
}

void Person::print()
{
    std::cout << "Name:    " << d_name << "\n"
                 "Address: " << d_address << '\n';
}

char const *Person::name()
{
    return d_name;
}

char const *Person::address()
{
    return d_address;
}

int main()
{
    Person person;

    person.setName("Pedro Moreira");
    person.setAddress("Brasília-DF");

    person.print();

    std::cout << "person.name()    = " << person.name() << std::endl;
    std::cout << "person.address() = " << person.address() << std::endl;

    return 0;
}
