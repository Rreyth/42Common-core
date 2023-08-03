#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria 
{
public:
	Cure( void );
	Cure(const Cure &obj);
	~Cure( void );

	AMateria*	clone() const;
	void use(ICharacter& target);

	Cure	&operator=(const Cure &obj);

private:

};

#endif
