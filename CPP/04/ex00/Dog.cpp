#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog created" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;
}

Dog & Dog::operator = (const Dog &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog goes : woof" << std::endl;
}
