#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal created" << std::endl;
	this->type = "none";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal type " << type << " created" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	if (type == "none")
		std::cout << "Default WrongAnimal destructed" << std::endl;
	else
		std::cout << "WrongAnimal type " << type << " destructed" << std::endl;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "What does the Wrongfox say?" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
