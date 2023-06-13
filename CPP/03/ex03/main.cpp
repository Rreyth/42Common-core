#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
/*	FragTrap Billy("Billy");
	ScavTrap Philippe("PhilippeB");

	Philippe.guardGate();
	Billy.attack("PhilippeB");
	Philippe.takeDamage(Billy.get_damage());
	Philippe.beRepaired(15);
	Philippe.attack("Billy");
	Billy.takeDamage(Philippe.get_damage());
	Billy.beRepaired(2);
	Philippe.takeDamage(100);
	Philippe.takeDamage(1);
	Philippe.beRepaired(1);
	Philippe.attack("Billy");
	Billy.highFivesGuys();
	std::cout << Billy << std::endl << Philippe << std::endl;*/

	DiamondTrap test("test");
	test.whoAmI();
	test.guardGate();
	test.highFivesGuys();
	std::cout << test << std::endl;
	return (0);
}