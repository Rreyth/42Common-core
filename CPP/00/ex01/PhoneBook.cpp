#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook() {
	this->pos = 0;
}

void	PhoneBook::add() {
	this->contact[this->pos].setf_name(this->get_field("First Name = "));
	this->contact[this->pos].setl_name(this->get_field("Last Name = "));
	this->contact[this->pos].setnickname(this->get_field("Nickname = "));
	this->contact[this->pos].setphone(this->get_field("Phone Number = "));
	this->contact[this->pos].setsecret(this->get_field("Darkest Secret = "));
	this->pos++;
	if (this->pos == 8)
		this->pos = 0;
}

void	PhoneBook::search() {
	std::string tmp;
	int index;

	for (int i = 0; i < 8; i++)
	{
		if (this->contact[i].getf_name().empty())
			break;
		std::cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10)
			<< this->format(this->contact[i].getf_name()) << "|" << std::setw(10)
			<< this->format(this->contact[i].getl_name()) << "|" << std::setw(10)
			<< this->format(this->contact[i].getnickname()) << "|" << std::endl;
	}
	if (this->contact[0].getf_name().empty())
		return ;
	std::cout << "Select index : ";
	std::getline(std::cin, tmp);
	index = atoi(tmp.c_str()) - 1;
	if (index < 0 || this->contact[index].getf_name().empty())
		std::cout << "Invalid index" << std::endl;
	else
	{
		std::cout << "First Name = " << this->contact[index].getf_name() << std::endl
			<< "Last Name = " << this->contact[index].getl_name() << std::endl
			<< "Nickname = " << this->contact[index].getnickname() << std::endl
			<< "Phone number = " << this->contact[index].getphone() << std::endl
			<< "Darkest secret = " << this->contact[index].getsecret() << std::endl;
	}
}

std::string PhoneBook::format(std::string str) {
	std::string res;

	if (str.length() <= 10)
		return str;
	res = str.substr(0, 10);
	res[9] = '.';
	return res;
}

std::string PhoneBook::get_field(std::string field) {
	std::string line;

	while (1)
	{
		std::cout << field;
		std::getline(std::cin, line);
		if (line.empty())
			std::cout << "Contact can’t have empty fields" << std::endl << std::endl;
		else
			return (line);
	}
}

PhoneBook::~PhoneBook() {

}
