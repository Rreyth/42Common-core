#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Billy("Billy");
	ClapTrap Philippe("PhilippeB");

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
	Philippe.takeDamage(20);
	Philippe.takeDamage(1);
	Philippe.beRepaired(1);
	Philippe.attack("Billy");
	return (0);
}