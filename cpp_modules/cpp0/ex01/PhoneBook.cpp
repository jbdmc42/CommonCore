#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void) {
	this->_contactCount = 0;			// as we start with no contacts added, the counter is initialized on '0'
	this->_indexToReplace = 0;			// first index to replace will always be [0] (first available one)
}

// Destructor
PhoneBook::~PhoneBook(void) {}

// strlen for strings with special characters
int		getVisualLength(std::string str) {
	int	len = 0;
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] < -64 || str[i] > -1)
			len++;
		i++;
	}
	return (len);
}

// custom alignment function
std::string	alignStringRightSizeTen(std::string str) {
	int			len = getVisualLength(str);
	int 		paddingNeeded = 10 - len;
	int			spaces = 0;
	std::string	alignedString;

	if (len == 10)
		return (str);
	while (spaces < paddingNeeded) {
		alignedString += " ";
		spaces++;
	}
	alignedString += str;
	return (alignedString);
}

// custom atoi
int	ft_customAtoi(std::string str, int numContacts) {
	int	value;
	int range;

	if (numContacts == 0)
		return (-1);
	range = numContacts + 47;
	if (str[0] < 48 || str[0] > range)		// if it's not a valid index for the number of contacts created (1 to 8)
		return (0);
	else {
		if (str[1] != '\0')
			return (0);
		return (value = str[0] - 47);		// always returns an index from 1 to 8, and then we subtract by 1 to get the actual index
	}
}

// ADD function
void	PhoneBook::addContact(void) {
	std::string input;
	Contact		newContact;									// creates a new Contact type class

	std::cout << "\n";
	// prompt for getting "First Name"
	while (input.empty()) {									// if the user presses 'ENTER' with no input the function just repeats itself
		std::cout << "\033[1;35mFirst name\033[0m: ";		// output of the program (same as scanf in C)
		std::getline(std::cin, input);						// getline gets the input from the user and writes in on 'input'
	}
	newContact.setFirstName(input);							// sets the private property 'firstName' to 'input' by using the setter function 'setFirstName'. Same flow will be used to set all other private properties of the class
	input.clear();											// sets input to an empty string variable

	// prompt for getting "Last Name"
	while (input.empty()) {
		std::cout << "\033[1;35mLast name\033[0m: ";
		std::getline(std::cin, input);
	}
	newContact.setLastName(input);
	input.clear();

	// prompt for getting "Nickname"
	while (input.empty()) {
		std::cout << "\033[1;35mNickname\033[0m: ";
		std::getline(std::cin, input);
	}
	newContact.setNickname(input);
	input.clear();

	// prompt for getting "Phone Number"
	while (input.empty()) {
		std::cout << "\033[1;35mPhone number\033[0m: ";
		std::getline(std::cin, input);
	}
	newContact.setPhoneNumber(input);
	input.clear();

	// prompt for getting "Darkest Secret"
	while (input.empty()) {
		std::cout << "\033[1;35mDarkest secret\033[0m: ";
		std::getline(std::cin, input);
	}
	newContact.setDarkestSecret(input);
	input.clear();

	// store the newly created contact in the fixed array
	this->_contacts[this->_indexToReplace] = newContact;

	// manage circular indexing (replace oldest if we go over 8)
	this->_indexToReplace = (this->_indexToReplace + 1) % 8;
	if (this->_contactCount < 8)
		this->_contactCount++;
	
	std::cout << "\n\033[1;36m>>> Contact added successfully! <<<\033[0m\n" << std::endl;
}

// SEARCH function
void	PhoneBook::searchContact(void) {
	// temporary string that will store the value of the property to print
	std::string	property;
	std::string	tempString;
	std::string option;
	int			index;

	std::cout << "\033[1;35m";		// set colour before print to prevent setw errors
	// print a header
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Nm" << "|";
	std::cout << std::right << std::setw(10) << "Last Nm" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

	std::cout << "\033[1;0m";		// set colour before print to make variables print in the correct colour
	// same as: int i = 0; while (i < this->_contactCount) { ...; i++; }
	for (int i = 0; i < this->_contactCount; i++) {
		// print the index
		std::cout << std::right << std::setw(10) << i << "\033[1;35m|\033[1;0m";

		// print 1st property (First Name)
		tempString = this->_contacts[i].getFirstName();
		property = alignStringRightSizeTen(this->_contacts[i].getFirstName());
		if (property == tempString)
			property = property.substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << property << "\033[1;35m|\033[1;0m";
		property.clear();
		tempString.clear();

		// print 2nd property (Last Name)
		tempString = this->_contacts[i].getLastName();
		property = alignStringRightSizeTen(this->_contacts[i].getLastName());
		if (property == tempString)
			property = property.substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << property << "\033[1;35m|\033[1;0m";
		property.clear();
		tempString.clear();

		// print 3rd property (Nickname)
		tempString = this->_contacts[i].getNickname();
		property = alignStringRightSizeTen(this->_contacts[i].getNickname());
		if (property == tempString)
			property = property.substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << property << std::endl;
		property.clear();
		tempString.clear();
	}

	// getting the option from the user
	while(option.empty()) {
		std::cout << "\n\033[1;35mIndex of the contact\033[0m: ";
		std::getline(std::cin, option);
		if (ft_customAtoi(option, this->_contactCount) == 0) {
			// error: out of range or wrong
			std::cout << "\n\033[1;31mInvalid index\033[0m: \033[1;31mplease choose an option from the table\033[1;0m." << std::endl;
			option.clear();
		}
		else if (ft_customAtoi(option, this->_contactCount) == -1) {
			// error: no contacts created
			std::cout << "\n\033[1;31mError\033[0m: \033[1;31mno contacts to search from\033[1;0m." << std::endl;
			std::cout << "\n\033[1;36m>>> Tip: add contacts by using ADD <<<\033[0m\n" << std::endl;
			option.clear();
			return ;
		}
		else {
			// print contact information
			index = ft_customAtoi(option, this->_contactCount) - 1;
			std::cout << "\n\033[1;36m>>> Contact found! <<<\033[0m\n" << std::endl;
			std::cout << "\n\033[1;36m========= Contact information =========> \033[0m" << std::endl;
			property = this->_contacts[index].getFirstName();
			std::cout << "\n\033[1;35m» First Name: \033[0m" << property << std::endl;
			property.clear();
			property = this->_contacts[index].getLastName();
			std::cout << "\n\033[1;35m» Last Name: \033[0m" << property << std::endl;
			property.clear();
			property = this->_contacts[index].getNickname();
			std::cout << "\n\033[1;35m» Nickname: \033[0m" << property << std::endl;
			property.clear();
			property = this->_contacts[index].getPhoneNumber();
			std::cout << "\n\033[1;35m» Phone number: \033[0m" << property << std::endl;
			property.clear();
			property = this->_contacts[index].getDarkestSecret();
			std::cout << "\n\033[1;35m» Darkest secret: \033[0m" << property << std::endl;
			std::cout << "\n\033[1;36m========= Contact information =========> \033[0m\n\n" << std::endl;
			property.clear();
			return ;
		}
	}
}

/* »»»»»»»»»»»»»»»»»»»»»»»»»»»»»» | NOTE | ««««««««««««««««««««««««««««««
** In the SEARCH function we were expected to use <iomanip> to reproduce the attended display. The issue is, when using
** characters that take more than 1 byte of space, functions like length() and size() stop working properly.
** As an example, if I wrote my name, João, that uses the character 'ã', this would count as 2 bytes and make the alignment fail.
** So, to prevent this problem, I chose to use my own alignment function alignStringRightSizeTen(std::string str) that takes a 
** string and adds the needed padding on the left of it, for the size of 10. It calculates the spaces needed based on the visual
** size of the string (the size/number of characters we see as a non-machine being) by using getVisualLength(std::string str), which
** is another function created by me, that returns an int for the visual size of the string passed. The string is then truncated if 
** it's size is 10, and as the align function returns a string, what I did was create a secundary string that holds the same string
** as property before it goes into alignStringRightSizeTen(), and then it compares both. As that function returns the own string if
** its size is 10, then comparison will return 1, executing the truncation by using substr(). Basically, my function recreates the
** behaviour of the functions setw() and right() from the std namespace.
*/