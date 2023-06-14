#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	FragTrap Billy("Billy");
	ScavTrap Philippe("PhilippeB");
	DiamondTrap Theodule("Theodule");

	std::cout << std::endl;
	Philippe.guardGate();
	Theodule.guardGate();
	Billy.attack("PhilippeB");
	Philippe.takeDamage(Billy.get_damage());
	Philippe.beRepaired(1);
	Philippe.attack("Billy");
	Billy.takeDamage(Philippe.get_damage());
	Billy.beRepaired(2);
	Theodule.attack("Billy & PhilippeB");
	Billy.takeDamage(Theodule.get_damage());
	Philippe.takeDamage(Theodule.get_damage());
	Philippe.attack("Theodule");
	Theodule.takeDamage(Philippe.get_damage());
	Billy.highFivesGuys();
	Theodule.highFivesGuys();
	Theodule.beRepaired(3);
	Theodule.whoAmI();
	std::cout << std::endl << Billy << std::endl << Philippe << std::endl << Theodule << std::endl;
	return (0);
}