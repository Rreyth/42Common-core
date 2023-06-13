#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &other);
			~ScavTrap();
			ScavTrap & operator = (const ScavTrap &other);
			void guardGate() const;
};

std::ostream & operator << (std::ostream &out, const ScavTrap &a);

#endif