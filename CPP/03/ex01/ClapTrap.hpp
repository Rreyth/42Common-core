#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	protected:
			std::string name;
			int	hit_points;
			int	energy_points;
			int attack_damage;
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(std::string name, int hit, int energy, int attack);
			ClapTrap(const ClapTrap &other);
			~ClapTrap();
			ClapTrap & operator = (const ClapTrap &other);
			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
			int get_damage() const;
			std::string get_name() const;
			int get_hp() const;
			int get_energy() const;
};

std::ostream & operator << (std::ostream &out, const ClapTrap &a);

#endif