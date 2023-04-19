#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact[8];
		int pos;
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		std::string format(std::string str);
		std::string get_field(std::string field);
};

#endif
