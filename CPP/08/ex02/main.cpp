#include <iostream>
#include <list>
#include "MutantStack.hpp"

int	main()
{
	{
		std::cout << "subject tests:" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << std::endl << "test with stack of int:" << std::endl;
		MutantStack<int> test;
		std::list<int> list;

		test.push(5);
		list.push_back(5);
		test.push(6);
		list.push_back(6);
		test.push(89);
		list.push_back(89);
		test.push(65);
		list.push_back(65);
		test.push(22);
		list.push_back(22);

		MutantStack<int>::container_type::iterator begin_it = test.begin();
		MutantStack<int>::container_type::iterator end_it = test.end();

		std::cout << "stack = {";
		while (begin_it != end_it)
		{
			std::cout << *begin_it;
			begin_it++;
			if (begin_it != end_it)
				std::cout << ", ";
		}
		std::cout << "}" << std::endl;

		std::list<int>::iterator begin_list = list.begin();
		std::list<int>::iterator end_list = list.end();

		std::cout << "list = {";
		while (begin_list != end_list)
		{
			std::cout << *begin_list;
			begin_list++;
			if (begin_list != end_list)
				std::cout << ", ";
		}
		std::cout << "}" << std::endl;
	}
	{
		std::cout << std::endl << "test with stack of string:" << std::endl;
		MutantStack<std::string> test;
		std::list<std::string> list;

		test.push("str1");
		list.push_back("str1");
		test.push("str2");
		list.push_back("str2");
		test.push("str3");
		list.push_back("str3");
		test.push("str4");
		list.push_back("str4");
		test.push("str5");
		list.push_back("str5");

		MutantStack<std::string>::container_type::iterator begin_it = test.begin();
		MutantStack<std::string>::container_type::iterator end_it = test.end();

		std::cout << "stack = {";
		while (begin_it != end_it)
		{
			std::cout << *begin_it;
			begin_it++;
			if (begin_it != end_it)
				std::cout << ", ";
		}
		std::cout << "}" << std::endl;

		std::list<std::string>::iterator begin_list = list.begin();
		std::list<std::string>::iterator end_list = list.end();

		std::cout << "list = {";
		while (begin_list != end_list)
		{
			std::cout << *begin_list;
			begin_list++;
			if (begin_list != end_list)
				std::cout << ", ";
		}
		std::cout << "}" << std::endl;
	}
	return (0);
}