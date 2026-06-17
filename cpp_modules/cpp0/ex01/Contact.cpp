#include "Contact.hpp"

// Constructor
Contact::Contact(void) {}

// Destructor
Contact::~Contact(void) {}

// FirstName
// Setter implementation
void Contact::setFirstName(std::string str) {
	this->_firstName = str;						// "this" is a pointer to the current object
}

// Getter implementation
std::string Contact::getFirstName(void) {
	return this->_firstName;
}

// LastName
void Contact::setLastName(std::string str) {
	this->_lastName = str;
}

std::string Contact::getLastName(void) {
	return this->_lastName;
}

// LastName
void Contact::setNickname(std::string str) {
	this->_nickname = str;
}

std::string Contact::getNickname(void) {
	return this->_nickname;
}

// LastName
void Contact::setPhoneNumber(std::string str) {
	this->_phoneNumber = str;
}

std::string Contact::getPhoneNumber(void) {
	return this->_phoneNumber;
}

// DarkestSecret
void Contact::setDarkestSecret(std::string str) {
	this->_darkestSecret = str;
}

std::string Contact::getDarkestSecret(void) {
	return this->_darkestSecret;
}