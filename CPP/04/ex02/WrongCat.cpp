#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat created" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal("WrongCat")
{
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed" << std::endl;
}

WrongCat & WrongCat::operator = (const WrongCat &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat goes : woof" << std::endl;
}
