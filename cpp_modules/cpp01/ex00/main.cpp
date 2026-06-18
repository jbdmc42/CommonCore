#include "Zombie.hpp"

int	main(void) {
	std::string	zombieName;
	std::string	option;
	Zombie*		zombie;

	while (zombieName.empty()) {
		std::cout << PURPLE << "\nChoose a name for your zombie" 
				  << WHITE << ": " << RESET;
		std::getline(std::cin, zombieName);
		if (!zombieName.empty()) {
			std::cout << CYAN << ">>> Name saved successfully <<<" << RESET << std::endl;
			while (option.empty()) {
				std::cout << PURPLE << "\nDo you want to create a" 
						  << CYAN << " HEAP " 
						  << PURPLE << "or"
						  << CYAN << " STACK "
						  << PURPLE << "zombie" 
						  << WHITE << "?" 
						  << PURPLE << "\n> " << RESET;
				std::getline(std::cin, option);
				if (option == "HEAP" || option == "STACK") {
					if (option == "HEAP") {
						std::cout << CYAN << "\n========== Creating "
								  << RED << "HEAP"
								  << CYAN << " zombie ==========\n" << RESET << std::endl;
						zombie = newZombie(zombieName);
						std::cout << PURPLE << "This zombie can't talk..." << RESET << std::endl;
						std::cout << CYAN << "\n========== Deleting "
								  << RED << "HEAP"
								  << CYAN << " zombie ==========\n" << RESET << std::endl;
						delete zombie;
					}
					else if (option == "STACK") {
						std::cout << CYAN << "\n========== Creating "
								  << RED << "STACK"
								  << CYAN << " zombie ==========\n" << RESET << std::endl;
						randomChump(zombieName);
					}
					return (0);
				}
				std::cout << RED << "\nError"
						  << WHITE << ": "
						  << RED << "please insert an option from the ones above"
						  << WHITE << ".\n" << RESET << std::endl;
				option.clear();
			}
		}
		std::cout << RED << "\nError"
				  << WHITE << ": "
				  << RED << "please insert a name for your zombie"
				  << WHITE << ".\n" << RESET << std::endl;
	}
	
}