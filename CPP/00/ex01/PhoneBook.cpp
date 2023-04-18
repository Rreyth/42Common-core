#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->pos = 0;
}

void	PhoneBook::add() {
	std::string line;

	std::cout << "First name = ";
	std::getline(std::cin, line);
	this->contact[this->pos].setf_name(line);
	std::cout << "Last name = ";
	std::getline(std::cin, line);
	this->contact[this->pos].setl_name(line);
	std::cout << "Nickname = ";
	std::getline(std::cin, line);
	this->contact[this->pos].setnickname(line);
	std::cout << "Phone number = ";
	std::getline(std::cin, line);
	this->contact[this->pos].setphone(line);
	std::cout << "Darkest secret = ";
	std::getline(std::cin, line);
	this->contact[this->pos].setsecret(line);
	this->pos++;
	if (this->pos == 8)
		this->pos = 0;
}

void	PhoneBook::search() {
	std::string tmp;

	tmp = this->contact[0].getf_name();
	if (tmp.length() > 10)
	{
		tmp[9] = '.';
		tmp[10] = '\0';
	}
	std::cout << std::setw(10);
	std::cout << tmp << "|";
	std::cout << std::setw(10);
	std::cout << "oui" << std::endl;
}

PhoneBook::~PhoneBook() {

}
