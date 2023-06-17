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
			using FragTrap::hit_points;
			using ScavTrap::energy_points;
			using FragTrap::attack_damage;
			using ScavTrap::attack;
};

std::ostream & operator << (std::ostream &out, const DiamondTrap &a);

#endif