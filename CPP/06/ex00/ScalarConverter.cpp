#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>

char	ScalarConverter::charValue = 0;
int		ScalarConverter::intValue = 0;
float	ScalarConverter::floatValue = 0.0f;
double	ScalarConverter::doubleValue = 0.0;
bool	ScalarConverter::possibleInt = true;
bool	ScalarConverter::possibleDouble = true;

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
ScalarConverter::ScalarConverter( void )
{

}


ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}


ScalarConverter::~ScalarConverter( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &obj)
{
	if (this == &obj)
		return (*this);
	charValue = obj.charValue;
	intValue = obj.intValue;
	floatValue = obj.floatValue;
	doubleValue = obj.doubleValue;
	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void	ScalarConverter::printValues()
{
	if (charValue < 0 || charValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (charValue < 32 || charValue > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
	if (possibleInt)
		std::cout << "int: " << intValue << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (possibleDouble)
	{
		if (doubleValue == (int)doubleValue)
		{
			std::cout << "float: " << floatValue << ".0f" << std::endl;
			std::cout << "double: " << doubleValue << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << floatValue << "f" << std::endl;
			std::cout << "double: " << doubleValue << std::endl;
		}
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void	ScalarConverter::convert(std::string initialValue)
{
	switch (getType(initialValue))
	{
	case C:
		charValue = initialValue[0];
		intValue = static_cast<int>(charValue);
		doubleValue = static_cast<double>(intValue);
		floatValue = static_cast<float>(intValue);
		break;
	case I:
		intValue = std::atoi(initialValue.c_str());
		if (!possibleInt)
			charValue = -1;
		else
			charValue = static_cast<char>(intValue);
		doubleValue = static_cast<double>(intValue);
		floatValue = static_cast<float>(intValue);
		break;
	case D:
		doubleValue = std::atof(initialValue.c_str());
		floatValue = static_cast<float>(doubleValue);
		intValue = static_cast<int>(doubleValue);		
		if ((intValue < 0 && initialValue[0] != '-') || (intValue > 0 && initialValue[0] == '-'))
			possibleInt = false;
		if (!possibleInt)
			charValue = -1;
		else	
			charValue = static_cast<char>(intValue);
		break;
	case F:
		floatValue = static_cast<float>(std::atof(initialValue.c_str()));
		doubleValue = static_cast<double>(floatValue);
		intValue = static_cast<int>(floatValue);
		if ((intValue < 0 && initialValue[0] != '-') || (intValue > 0 && initialValue[0] == '-'))
			possibleInt = false;
		if (!possibleInt)
			charValue = -1;
		else	
			charValue = static_cast<char>(intValue);
		break;
	default:
		charValue = -1;
		possibleInt = false;
		possibleDouble = false;
		break;
	}
	printValues();
}

e_type	ScalarConverter::getType(std::string tested)
{
	double	test = std::atof(tested.c_str());

	if ((test == 0 && tested[0] != '0' && tested.size() == 1) || tested.size() == 0)
		return (C);
	if ((tested == "nan" || tested == "nanf" || tested == "inf" || tested == "inff" || tested == "-inf" || tested == "-inff" || tested == "+inf" || tested == "+inff")
		|| ((tested.find('.', 0) != std::string::npos || test > std::numeric_limits<int>::max() || test < std::numeric_limits<int>::min())
		&& ((test < 0 && tested[0] == '-') || (test > 0 && tested[0] != '-'))))
	{
		if ((tested == "nanf" || tested == "inff" || tested == "-inff" || tested == "+inff") || (tested[tested.size() - 1] == 'f'
			&& test <= std::numeric_limits<float>::max() && test >= std::numeric_limits<float>::min()))
			return (F);
		else if (tested[tested.size() - 1] == 'f' && (test > std::numeric_limits<float>::max() || test < std::numeric_limits<float>::min()))
			return (S);
		return (D);
	}
	if (test == 0 && tested[0] != '0')
		return (S);
	if (test == (int)test && test <= std::numeric_limits<int>::max() && test >= std::numeric_limits<int>::min())
		return (I);
	return (S);
}


////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
