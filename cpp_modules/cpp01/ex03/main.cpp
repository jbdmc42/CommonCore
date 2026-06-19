#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	askedForMercy(std::string input) {
	if (input == "MERCY") {
		std::cout << CYAN << "\n>>> You ran from the battlefield <<<" << RESET << std::endl;
		std::cout << BROWNISH << "================ THE BATTLE IS OVER ================" << RESET << std::endl;
		return (1); 
	}
	else
		return (0);
}

int	main(void) {
	std::string firstWeapon;
	std::string secondWeapon;
	std::string firstName;
	std::string secondName;
	std::string	armed;

	std::cout << CLEAR_SCREEN;
	std::cout << BROWNISH << "============ WELCOME TO THE BATTLEFIELD ============" << RESET << std::endl;
	std::cout << CYAN << ">>> Say MERCY to leave the battlefield <<<" << RESET << std::endl;
	while (firstName.empty()) {
		std::cout << PURPLE << "\nWhat is your name" << WHITE << ", " << PURPLE << "warrior" << WHITE << "?\n> " << RESET;
		std::getline(std::cin, firstName);

		if (askedForMercy(firstName))
			return (0);
		// firstName is full
		if (!firstName.empty()) {
			while (armed.empty()) {
				std::cout << PURPLE << "\nDid you bring your weapon " << RED << firstName << WHITE << "?\n> " << RESET;
				std::getline(std::cin, armed);
				
				if (askedForMercy(armed))
					return (0);
				if (!armed.empty() && (armed == "yes" || armed == "no")) {
					if (armed == "yes") {
						while (firstWeapon.empty()) {
							std::cout << PURPLE << "What is your weapon" << WHITE << ", " << PURPLE "brave warrior" << WHITE << "?\n> " << RESET;
							std::getline(std::cin, firstWeapon);

							if (askedForMercy(firstWeapon))
								return (0);
							if (!firstWeapon.empty())
								break ;
							firstWeapon = "fist";
							std::cout << RED << "\nArmed with your fist" << WHITE << "!" << RED << " That's what I like to see" << WHITE << "!" << RESET << std::endl;
						}
					}
					else if (armed == "no") {
						firstWeapon = '\0';
						std::cout << RED << "\nYou are brave warrior" << WHITE << ", " << RED << "but also crazy" << WHITE << "!" << RESET << std::endl;
					}
					while (secondName.empty()) {
						std::cout << PURPLE << "\nAnd the name of your opponent is..." << WHITE << "\n> " << RESET;
						std::getline(std::cin, secondName);

						if (askedForMercy(secondName))
							return (0);
						if (!secondName.empty()) {
							while (secondWeapon.empty()) {
								std::cout << PURPLE << "\nAnd he is armed with..." << WHITE << "\n> " << RESET;
								std::getline(std::cin, secondWeapon);

								if (askedForMercy(secondWeapon))
									return (0);
								if (!secondWeapon.empty()) {
									std::cout << BROWNISH << "================ THE BATTLE BEGGINS ================" << RESET << std::endl;
									Weapon opponentWeapon(secondWeapon);

									HumanA* opponent = new HumanA(opponentWeapon, secondName);
									
									HumanB* player = new HumanB(firstName);

									if (armed == "yes") {
										Weapon *playerWeapon = new Weapon(firstWeapon);
										player->setWeapon(*playerWeapon);

										opponent->attack();
										player->attack();

										delete opponent;
										delete player;
										delete playerWeapon;
									}
									else {
										opponent->attack();
										player->attack();
										
										delete opponent;
										delete player;
									}
									std::cout << BROWNISH << "\n================ THE BATTLE IS OVER ================" << RESET << std::endl;
									return (0);
								}
								// case secondWeapon is empty
								std::cout << CLEAR_SCREEN << RED << "------------------------------" << RESET << std::endl;
								std::cout << RED << "YOUR OPPONENT IS ALWAYS ARMED!" << RESET << std::endl; 
							}
						}
						// secondName is empty
						std::cout << CLEAR_SCREEN << RED << "-------------------------" << RESET << std::endl;
						std::cout << RED << "EVERY WARRIOR HAS A NAME!" << RESET << std::endl;
					}
				}
				else if (armed != "yes" || armed != "no") {
					// case input differs from yes/no
					std::cout << CLEAR_SCREEN << RED << "---------------------------------" << RESET << std::endl;
					std::cout << RED << "YOU HAVE TO ANSWER ME, YES OR NO!" << RESET << std::endl;
					armed.clear();
				}

				std::cout << CLEAR_SCREEN << RED << "---------------------------------" << RESET << std::endl;
				std::cout << RED << "YOU HAVE TO ANSWER ME, YES OR NO!" << RESET << std::endl;
			}
		}
		// firstName is empty
		std::cout << CLEAR_SCREEN << RED << "-------------------------" << RESET << std::endl;
		std::cout << RED << "EVERY WARRIOR HAS A NAME!" << RESET << std::endl;
	}
}