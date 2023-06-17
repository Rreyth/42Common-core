#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "Default ScavTrap constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructed." << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &other)
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

void ScavTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
	{
		std::cout << "ScavTrap " << name << " is dead it can't attack." << std::endl;
		return;
	}
	if (energy_points <= 0)
	{
		std::cout << "ScavTrap " << name << " don't have enough energy it can't attack." << std::endl;
		return;
	}
	energy_points -= 1;
	std::cout << "ScavTrap " << name << " attacks " << target << ", dealing " << attack_damage << " points of damage!" << std::endl;
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
