#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
public:
	IMateriaSource( void );
	IMateriaSource(const IMateriaSource &obj);
	virtual ~IMateriaSource( void );

	virtual void learnMateria(AMateria* m) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;

	IMateriaSource	&operator=(const IMateriaSource &obj);

private:
};

#endif
