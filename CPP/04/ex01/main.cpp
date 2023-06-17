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
	dog.mod_idea(0, "testui");
    dog.print_ideas(5);
	Dog cpdog = dog;
	cpdog.print_ideas(5);
	}
	return 0;
}