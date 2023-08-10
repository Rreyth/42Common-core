#include <iostream>
#include "templates.hpp"

int	main()
{
	{
		std::cout << "subject tests:" << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << std::endl << "tests with double:" << std::endl;
		double test1 = 5.9;
		double test2 = 98.6;
		::swap( test1, test2 );
		std::cout << "test1 = " << test1 << ", test2 = " << test2 << std::endl;
		std::cout << "min( test1, test2 ) = " << ::min( test1, test2 ) << std::endl;
		std::cout << "max( test1, test2 ) = " << ::max( test1, test2 ) << std::endl;

		std::cout << std::endl << "const tests:" << std::endl;
		const int a = 5;
		const int b = 8;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		const std::string c = "ccccc";
		const std::string d = "ddddd";
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return (0);
}