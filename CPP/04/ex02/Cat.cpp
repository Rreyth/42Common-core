#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat created" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal("Cat")
{
	brain = NULL;
	*this = other;
}

Cat::~Cat()
{
	delete(brain);
	std::cout << "Cat destructed" << std::endl;
}

Cat & Cat::operator = (const Cat &other)
{
	if (this != &other)
	{
		type = other.type;
		if (brain)
			delete(brain);
		brain = new Brain(*other.brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat goes : meow" << std::endl;
}

void Cat::print_ideas(int nb) const
{
	std::cout << "Cat ideas:" << std::endl;
	for (int i = 0; i < nb; i++)
		std::cout << brain->get_idea(i) << std::endl;
}

void Cat::mod_idea(int i, std::string new_idea)
{
	brain->set_idea(i, new_idea);
}