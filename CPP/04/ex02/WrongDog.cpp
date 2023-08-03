#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
	std::cout << "WrongDog created" << std::endl;
	type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal("WrongDog")
{
	*this = other;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructed" << std::endl;
}

WrongDog & WrongDog::operator = (const WrongDog &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void WrongDog::makeSound() const
{
	std::cout << "WrongDog goes : meow" << std::endl;
}
