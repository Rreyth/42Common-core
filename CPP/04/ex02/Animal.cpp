#include "Animal.hpp"

Animal::Animal()
{
	this->type = "none";
	std::cout << "Default Animal created" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal type " << type << " created" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal::~Animal()
{
	if (type == "none")
		std::cout << "Default Animal destructed" << std::endl;
	else
		std::cout << "Animal type " << type << " destructed" << std::endl;
}

Animal & Animal::operator = (const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "What does the fox say?" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
