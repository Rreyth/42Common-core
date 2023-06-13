#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Billy("Billy");
	ScavTrap Philippe("PhilippeB");

	Philippe.guardGate();
	Billy.attack("PhilippeB");
	Philippe.takeDamage(Billy.get_damage());
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.beRepaired(1);
	Philippe.attack("Billy");
	Billy.takeDamage(Philippe.get_damage());
	Billy.beRepaired(2);
	Philippe.takeDamage(100);
	Philippe.takeDamage(1);
	Philippe.beRepaired(1);
	Philippe.attack("Billy");
	std::cout << Billy << std::endl << Philippe << std::endl;
	return (0);
}