#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat created" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &other) : Animal("Cat")
{
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Cat destructed" << std::endl;
}

Cat & Cat::operator = (const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat goes : meow" << std::endl;
}
