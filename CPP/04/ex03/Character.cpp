#include "Character.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
Character::Character( void )
{
	this->name = "Default";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	floor = NULL;
	nb_on_floor = 0;
}


Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	floor = NULL;
	nb_on_floor = 0;
}


Character::Character(const Character &obj)
{
	*this = obj;
}


Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
	for (int i = 0; floor && i < nb_on_floor; i++)
		delete floor[i];
	delete [] floor;
}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////

std::string const & Character::getName() const
{
	return (name);
}

////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
Character	&Character::operator=(const Character &obj)
{
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
	for (int i = 0; i < 4; i++)
		if (obj.inventory[i])
			inventory[i] = obj.inventory[i]->clone();
	name = obj.name;
	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::realloc_floor(int i)
{
	AMateria *tmp[i];

	for (int j = 0; j < i; j++)
	{
		std::cout << i << " " << j << " " << this->name << std::endl;
		tmp[j] = this->floor[j];
	}

	delete [] this->floor;
	
	this->floor = new AMateria *[i];

	for (int j = 0; j < i; j++)
		this->floor[j] = tmp[j];
}

void Character::to_floor(AMateria *unequip)
{
	if (nb_on_floor == 0)
	{
		this->floor = new AMateria*[1];
		this->floor[0] = unequip;
	}
	else
	{
		this->realloc_floor(nb_on_floor);	
		this->floor[nb_on_floor] = unequip;
	}

	nb_on_floor++;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		to_floor(inventory[idx]);
		inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
