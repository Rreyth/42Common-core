#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
	std::cout << "subject main :" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	}
	{
	std::cout << std::endl << "test ideas and copy :" << std::endl;
	Dog dog;
	Cat cat;
	std::cout << "Default ideas :" << std::endl;
	dog.print_ideas(5);
	dog.mod_idea(0, "testui");
	std::cout << "modified ideas :" << std::endl;
    dog.print_ideas(5);
	Dog cpdog = dog;
	std::cout << "copy ideas :" << std::endl;
	cpdog.print_ideas(5);
	}
	{
	std::cout << std::endl << "Array of animals test :" << std::endl;
	int i = 10;
	Animal **tab = new Animal*[i];

	for (int j = 0; j < i; j++)
	{
		if (j < i / 2)
			tab[j] = new Dog();
		else
			tab[j] = new Cat();
	}
	for (int j = 0; j < i; j++)
	{
		delete tab[j];
	}
	delete [] tab;
	}
	return 0;
}