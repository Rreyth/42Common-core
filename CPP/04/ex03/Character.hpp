#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character( void );
	Character(std::string name);
	Character(const Character &obj);
	~Character( void );

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void to_floor(AMateria *unequip);
	void realloc_floor(int i);

	Character	&operator=(const Character &obj);

private:
	std::string	name;
	AMateria 	*inventory[4];
	AMateria	**floor;
	int			nb_on_floor;
};

#endif
