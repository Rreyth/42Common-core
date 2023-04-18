#include "Contact.hpp"

Contact::Contact() {
	this->f_name = "";
	this->l_name = "";
	this->nickname = "";
	this->phone = "";
	this->secret = "";
}

Contact::~Contact() {

}

void Contact::setf_name(std::string f_name) {
	this->f_name = f_name;
}

void Contact::setl_name(std::string l_name) {
	this->l_name = l_name;
}

void Contact::setnickname(std::string nickname) {
	this->nickname = nickname;
}

void Contact::setphone(std::string phone) {
	this->phone = phone;
}

void Contact::setsecret(std::string secret) {
	this->secret = secret;
}

std::string Contact::getf_name() {
	return this->f_name;
}

std::string Contact::getl_name() {
	return this->l_name;
}

std::string Contact::getnickname() {
	return this->nickname;
}

std::string Contact::getphone() {
	return this->phone;
}

std::string Contact::getsecret() {
	return this->secret;
}
