#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource( void );
	MateriaSource(const MateriaSource &obj);
	~MateriaSource( void );

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);

	MateriaSource	&operator=(const MateriaSource &obj);

private:
	AMateria	*templates[4];
};

#endif
