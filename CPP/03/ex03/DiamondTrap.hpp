#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
			std::string name;
	public:
			DiamondTrap();
			DiamondTrap(std::string name);
			DiamondTrap(const DiamondTrap &other);
			~DiamondTrap();
			DiamondTrap & operator = (const DiamondTrap &other);
			void whoAmI();
};

std::ostream & operator << (std::ostream &out, const DiamondTrap &a);

#endif