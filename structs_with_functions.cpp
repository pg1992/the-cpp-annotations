#include <iostream>
#include <cstring>

struct Person {
	char name[80];
	char address[80];

	void print();
};

void Person::print()
{
	std::cout << "Name:    " << name << "\n"
		     "Address: " << address << '\n';
}

int main()
{
	Person person;

	strcpy(person.name, "Pedro Guilherme");
	strcpy(person.address, "Rua Dr. Ruy Vicente de Mello");
	person.print();

	return 0;
}
