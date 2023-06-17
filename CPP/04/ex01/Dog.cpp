#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog created" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	brain = NULL;
	*this = other;
}

Dog::~Dog()
{
	delete(brain);
	std::cout << "Dog destructed" << std::endl;
}

Dog & Dog::operator = (const Dog &other)
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

void Dog::makeSound() const
{
	std::cout << "Dog goes : woof" << std::endl;
}

void Dog::print_ideas(int nb) const
{
	std::cout << "Dog ideas:" << std::endl;
	for (int i = 0; i < nb; i++)
		std::cout << brain->get_idea(i) << std::endl;
}

void Dog::mod_idea(int i, std::string new_idea)
{
	brain->set_idea(i, new_idea);
}
