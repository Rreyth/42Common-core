#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main()
{
	{
		std::vector<int> v;
		v.push_back(58);
		v.push_back(95);
		v.push_back(12);
		v.push_back(45);
		v.push_back(1);
		v.push_back(6);
		std::cout << "test with vector container:" << std::endl;
		std::cout << "vector = {";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << ", ";
		std::cout << "}" << std::endl;
		try
		{
			std::cout << "pos of 45 in vector: " << easyfind(v, 45) << std::endl;
			std::cout << "pos of 666 in vector: " << easyfind(v, 666) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::list<int> l;
		l.push_back(12);
		l.push_back(96);
		l.push_back(7);
		l.push_back(2);
		l.push_back(0);
		l.push_back(999);
		std::cout << std::endl << "test with list container:" << std::endl;
		std::cout << "list = {";
		for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
			std::cout << *it << ", ";
		std::cout << "}" << std::endl;
		try
		{
			std::cout << "pos of 0 in list: " << easyfind(l, 0) << std::endl;
			std::cout << "pos of 666 in list: " << easyfind(l, 666) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}