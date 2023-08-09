#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

enum e_type{
	C,
	I,
	D,
	F,
	S
};

class ScalarConverter
{
public:

	static e_type	getType(std::string);
	static void		convert(std::string);
	static void		printValues();

private:
	ScalarConverter( void );
	ScalarConverter(const ScalarConverter &obj);
	~ScalarConverter( void );
	ScalarConverter	&operator=(const ScalarConverter &obj);

	static char		charValue;
	static int		intValue;
	static float	floatValue;
	static double	doubleValue;
	static bool		possibleInt;
	static bool		possibleDouble;
};

#endif
