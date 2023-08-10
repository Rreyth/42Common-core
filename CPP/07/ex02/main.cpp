#include <iostream>
#include "Array.hpp"


int	main()
{
	{
	std::cout << "int tests:" << std::endl;
	
	Array<int> array1;
	std::cout << "array1(default constructor) size = " << array1.size() << std::endl;

	Array<int> array2(5);
	std::cout << "array2(constructor with size 5) size = " << array2.size() << std::endl;

	Array<int> array3(array2);
	std::cout << "array3(copy of array2) size = " << array3.size() << std::endl;
	
	try
	{
		std::cout << array2[2] << std::endl;
		std::cout << array2[6] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	}
	{
	std::cout << std::endl << "double tests:" << std::endl;
	Array<double> array1;
	std::cout << "array1(default constructor) size = " << array1.size() << std::endl;

	Array<double> array2(5);
	std::cout << "array2(constructor with size 5) size = " << array2.size() << std::endl;

	Array<double> array3(array2);
	std::cout << "array3(copy of array2) size = " << array3.size() << std::endl;

	try
	{
		std::cout << array2[2] << std::endl;
		std::cout << array2[6] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	}
	{
	std::cout << std::endl << "string tests:" << std::endl;
	Array<std::string> array1;
	std::cout << "array1(default constructor) size = " << array1.size() << std::endl;

	Array<std::string> array2(5);
	std::cout << "array2(constructor with size 5) size = " << array2.size() << std::endl;

	Array<std::string> array3(array2);
	std::cout << "array3(copy of array2) size = " << array3.size() << std::endl;

	try
	{
		std::cout << array2[2] << std::endl;
		std::cout << array2[6] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	}
	return (0);
}