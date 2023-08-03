#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
			std::string	type;
	public:
			WrongCat();
			WrongCat(const WrongCat &other);
			~WrongCat();
			WrongCat & operator = (const WrongCat &other);
			void makeSound() const;
};

#endif