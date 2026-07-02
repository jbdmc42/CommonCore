#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug() {
	std::cout << CYAN << "DEBUG: " << PURPLE << "this message shows that the private method called from the Harl class was 'debug()'" << RESET << std::endl;
}

void	Harl::info() {
	std::cout << CYAN << "INFO: " << PURPLE << "this message shows that the private method called from the Harl class was 'info()'" << RESET << std::endl;
}

void	Harl::warning() {
	std::cout << RED << "WARNING: " << PURPLE << "this message shows that the private method called from the Harl class was 'warning()'" << RESET << std::endl;
}

void	Harl::error() {
	std::cout << RED << "ERROR: " << PURPLE << "this message shows that the private method called from the Harl class was 'error()'" << RESET << std::endl;
}

void Harl::complain(std::string level) {
	// 1. define the array of member functions
	void (Harl::*funcs[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	// 2. define the corresponding level strings
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << CYAN << "[ The mentioned level " << PURPLE << "'" << level << "'" << CYAN <<" is not a valid type ]" << RESET << std::endl; 
}