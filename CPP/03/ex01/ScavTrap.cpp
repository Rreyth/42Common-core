#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "Default ScavTrap constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name, other.hit_points, other.energy_points, other.attack_damage)
{
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructed." << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->attack_damage = other.attack_damage;
	this->energy_points = other.energy_points;
	return (*this);
}

void ScavTrap::guardGate() const
{
	std::cout << name << " is now in Gate keeper mode." << std::endl;
}

std::ostream & operator << (std::ostream &out, const ScavTrap &a)
{
	out << "name = " << a.get_name() << std::endl << "hp = " << a.get_hp() << std::endl << "energy = " << a.get_energy() << std::endl << "attack damage = " << a.get_damage() << std::endl;
	return (out);
}
