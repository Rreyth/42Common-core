#include "IMateriaSource.hpp"

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
IMateriaSource::IMateriaSource( void )
{

}


IMateriaSource::IMateriaSource(const IMateriaSource &obj)
{
	(void) obj;
}


IMateriaSource::~IMateriaSource( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
IMateriaSource	&IMateriaSource::operator=(const IMateriaSource &obj)
{
	if (this == &obj)
		return (*this);

	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
