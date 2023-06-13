#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30)
{
	std::cout << "Default FragTrap constructed." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name, other.hit_points, other.energy_points, other.attack_damage)
{
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructed." << std::endl;
}

FragTrap & FragTrap::operator = (const FragTrap &other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->attack_damage = other.attack_damage;
	this->energy_points = other.energy_points;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " : give me a high five." << std::endl;
}

std::ostream & operator << (std::ostream &out, const FragTrap &a)
{
	out << "name = " << a.get_name() << std::endl << "hp = " << a.get_hp() << std::endl << "energy = " << a.get_energy() << std::endl << "attack damage = " << a.get_damage() << std::endl;
	return (out);
}
