#include "Zombie.hpp"

// for message randomization purposes
#include <cstdlib>
#include <ctime>

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string name) : name(name) {
	std::cout << CYAN ">>> The zombie "
			  << RED << this->name
			  << CYAN << " was created successfully <<<\n\n" << RESET << std::endl;
}

Zombie::~Zombie() {
	std::cout << CYAN << ">>> The zombie "
			  << RED << this->name
			  << CYAN << " will die now <<<\n\n" << RESET << std::endl;
}

void    Zombie::setName(std::string name) {
    this->name = name;
}

void	Zombie::announceRandomized() {
	// 1. randomize value
	int			i = std::rand() % 13;

	// 2. set pre-determined message array
	std::string	messages[13] = {
		"BraiiiiiiinnnzzzZ...",
		"ZoooombiezzzzZ... Areee commingggG...",
		"Gruuuaaar!!!",
		"*burp*",
		"*sniff* I smelll braiiinzzzzZ...", 
		"Eaaaat... braiiiinzZ...",
		"Uuuuuuurrr...",
		"Grooar?",
		"Bluuuh...",
		"Whereeee areee the braiiinzzzZ???",
		"I need meat...",
		"Arrrgghhh...",
		"More... brains..."
	};

	// 3. print message
	std::cout << RED << "" << this->name
			  << WHITE << ": "
			  << BROWNISH << messages[i] <<"\n" << RESET << std::endl;
}