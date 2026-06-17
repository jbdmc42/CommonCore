#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];		// fixed array of 8 'Contact' objects on the stack
		int		_contactCount;		// tracks how many total contacts have been 
		int		_indexToReplace;	// tracks the oldest contact index to overwrite (0 to 7)

	public:
		PhoneBook(void);
		~PhoneBook(void);

		// Setter function
		void addContact(void);
		// Getter function
		void searchContact(void);
};

#endif