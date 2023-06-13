#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name", 100, 50, 30)
{
	std::cout << "Default DiamondTrap constructed." << std::endl;
	this->name = "Default";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30)
{
	std::cout << "DiamondTrap " << name << " constructed." << std::endl;
	this->name = name;
}
/*
DiamondTrap::DiamondTrap(const DiamondTrap &other) : FragTrap(other.name), ScavTrap(name)
{
	this->name = other.name;
}*/

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
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->attack_damage = other.attack_damage;
	this->energy_points = other.energy_points;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const DiamondTrap &a)
{
	out << "name = " << a.get_name() << std::endl << "hp = " << a.get_hp() << std::endl << "energy = " << a.get_energy() << std::endl << "attack damage = " << a.get_damage() << std::endl;
	return (out);
}