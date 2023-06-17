#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
			std::string	type;
			Brain* brain;
	public:
			Dog();
			Dog(const Dog &other);
			~Dog();
			Dog & operator = (const Dog &other);
			void makeSound() const;
			void print_ideas(int nb) const;
			void mod_idea(int i, std::string new_idea);
};

#endif