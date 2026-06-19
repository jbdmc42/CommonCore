#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact				// class declaration and name
{
	private:				// private part of the class (only accessible inside it)
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:					// public part of the class (accessible from other parts of the code)
		Contact(void);			// constructor
		~Contact(void);			// destructor

		// setter functions
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickname(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);

		// getter functions
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
};

#endif