#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void) {
	PhoneBook	phoneBook;	// contact array
	std::string	command;	// command from the user input

	while (true) {			// infinite loop (listener)
		std::cout << "\n\033[1;35mEnter a command from the list\033[1;0m:\033[0m \n> ADD \n> SEARCH \n> EXIT" << std::endl;
		std::cout << "\n» ";
		if (!std::getline(std::cin, command)) {
			break ;
		}
		if (command == "ADD") {
			phoneBook.addContact();
		}
		else if (command == "SEARCH") {
			phoneBook.searchContact();
		}
		else if (command == "EXIT") {
			break ;
		}
		else if (!command.empty()) {
			std::cout << "\n\033[1;31mInvalid command\033[0m: \033[1;31mcheck the list for available commands\033[1;0m." << std::endl;
		}
	}
	std::cout << "\n\033[1;36m>>> Goodbye! <<<\033[0m\n" << std::endl;
	return 0;
}