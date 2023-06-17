#include "Brain.hpp"

std::string ft_itos(int i)
{
	std::stringstream ss;
	ss << i;
	return (ss.str());
}

Brain::Brain()
{
	std::cout << "Brain constructed" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		ideas[i] = "idea " + ft_itos(i);
	}
}

Brain::Brain(const Brain &other)
{
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}

Brain & Brain::operator = (const Brain &other)
{
	if (this != &other)
		std::copy(other.ideas, other.ideas + 100, this->ideas);
	return (*this);
}

std::string Brain::get_idea(int i) const
{
	return (ideas[i]);
}

void Brain::set_idea(int i, std::string new_idea)
{
	ideas[i] = new_idea;
}
