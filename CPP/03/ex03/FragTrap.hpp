#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public virtual ClapTrap
{
	public:
			FragTrap();
			FragTrap(std::string name);
			FragTrap(const FragTrap &other);
			~FragTrap();
			FragTrap & operator = (const FragTrap &other);
			void highFivesGuys(void);
};

std::ostream & operator << (std::ostream &out, const FragTrap &a);

#endif