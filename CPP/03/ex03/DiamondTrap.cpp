#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name")
{
	std::cout << "Default DiamondTrap constructed." << std::endl;
	name = "Default";
	FragTrap::hit_points = 100;
	ScavTrap::energy_points = 50;
	FragTrap::attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap " << name << " constructed." << std::endl;
	this->name = name;
	FragTrap::hit_points = 100;
	ScavTrap::energy_points = 50;
	FragTrap::attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(), FragTrap()
{
	this->name = other.name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destructed." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "my name is : " << name << " and my ClapTrap name is : " << get_name() << std::endl;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
	}
	return (*this);
}

std::ostream & operator << (std::ostream &out, const DiamondTrap &a)
{
	out << "name = " << a.get_name() << std::endl << "hp = " << a.get_hp() << std::endl << "energy = " << a.get_energy() << std::endl << "attack damage = " << a.get_damage() << std::endl;
	return (out);
}