#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice(const Ice &obj);
	~Ice( void );

	AMateria* clone() const;
	void use(ICharacter& target);

	Ice	&operator=(const Ice &obj);

private:

};

#endif
