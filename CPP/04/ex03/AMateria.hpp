#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
public:
	AMateria( void );
	AMateria(std::string const & type);
	AMateria(const AMateria &obj);
	virtual ~AMateria( void );

	AMateria	&operator=(const AMateria &obj);

	std::string const & getType() const;
	void	setType(std::string const & type);
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string type;
};

#endif
