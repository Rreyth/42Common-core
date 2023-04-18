#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	private:
		std::string f_name;
		std::string l_name;
		std::string nickname;
		std::string phone;
		std::string secret;
	public:
		Contact();
		~Contact();
		void setf_name(std::string f_name);
		void setl_name(std::string l_name);
		void setnickname(std::string nickname);
		void setphone(std::string phone);
		void setsecret(std::string secret);
		std::string getf_name();
		std::string getl_name();
		std::string getnickname();
		std::string getphone();
		std::string getsecret();
};

#endif
