#include "Zombie.hpp"

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

void	Zombie::announce() {
	std::cout << RED << "" << this->name
			  << WHITE << ": "
			  << BROWNISH << "BraiiiiiiinnnzzzZ...\n" << RESET << std::endl;
}