#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructed." << std::endl;
	this->name = "Default";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name, int hit, int energy, int attack)
{
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
	this->name = name;
	hit_points = hit;
	energy_points = energy;
	attack_damage = attack;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructed." << std::endl;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		attack_damage = other.attack_damage;
		energy_points = other.energy_points;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
	{
		std::cout << name << " is dead it can't attack." << std::endl;
		return;
	}
	if (energy_points <= 0)
	{
		std::cout << name << " don't have enough energy it can't attack." << std::endl;
		return;
	}
	energy_points -= 1;
	std::cout << name << " attacks " << target << ", dealing " << attack_damage << " points of damage!" << std::endl;	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout << name << " is already dead it can't take damage anymore." << std::endl;
		return;
	}
	std::cout << name << " take " << amount << " points of damage." << std::endl;
	if ((int)amount > hit_points)
		hit_points = 0;
	else
		hit_points -= amount;
	if (hit_points == 0)
		std::cout << name << " Died." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout << name << " is dead it can't be repaired." << std::endl;
		return;
	}
	if (energy_points <= 0)
	{
		std::cout << name << " don't have enough energy it can't repair itself." << std::endl;
		return;
	}
	energy_points -= 1;
	hit_points += amount;
	std::cout << name << " repare itself for " << amount << " health points." << std::endl;
}

int ClapTrap::get_damage() const
{
	return (attack_damage);
}

std::string ClapTrap::get_name() const
{
	return (name);
}

int ClapTrap::get_energy() const
{
	return (energy_points);
}

int ClapTrap::get_hp() const
{
	return (hit_points);
}

std::ostream & operator << (std::ostream &out, const ClapTrap &a)
{
	out << "name = " << a.get_name() << std::endl << "hp = " << a.get_hp() << std::endl << "energy = " << a.get_energy() << std::endl << "attack damage = " << a.get_damage() << std::endl;
	return (out);
}
