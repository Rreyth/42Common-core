#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
			std::string	type;
			Brain* brain;
	public:
			Cat();
			Cat(const Cat &other);
			~Cat();
			Cat & operator = (const Cat &other);
			void makeSound() const;
			void print_ideas(int nb) const;
			void mod_idea(int i, std::string new_idea);
};

#endif