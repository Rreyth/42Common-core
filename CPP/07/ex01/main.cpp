#include <iostream>
#include "iter.hpp"


int	main()
{
	std::cout << "test on string type:" << std::endl;
	std::string str[5] = {"str1", "str2", "str3", "str4", "str5"};
	::iter(str, 5, ::printfct<std::string>);

	std::cout << std::endl << "test on int type:" << std::endl;
	int	i[5] = {1, 2, 3, 4, 5};
	::iter(i, 5, ::printfct<int>);

	std::cout << std::endl << "test on double type:" << std::endl;
	double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(d, 5, ::printfct<double>);

	return (0);
}