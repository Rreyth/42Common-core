#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	private:
			std::string	type;
	public:
			WrongDog();
			WrongDog(const WrongDog &other);
			~WrongDog();
			WrongDog & operator = (const WrongDog &other);
			void makeSound() const;
};

#endif