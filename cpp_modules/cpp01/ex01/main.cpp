#include "Zombie.hpp"
#include <ctime>
#include <cstdlib>

int	ft_customAtoi(std::string str) {
	int	value = 0;
	int	i = 0;

	if (str[0] < 48 || str[0] > 57)
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i]) {
		if (str[i] == '\0')
			break ;
		else if ((str[i] >= 48 && str[i] <= 57)) {
			value = (value * 10) + (str[i] - 48);
			i++;
		}
		else
			return (0);
	}
	return (value);
}

int	main(void) {
	std::string	zombieHordeName;
	std::string	hordeSizeInput;
	int			hordeSize;
	Zombie		*zombies;

	// await user input for horde name
	while (zombieHordeName.empty()) {
		std::cout << PURPLE << "\nChoose a name for your zombie horde" 
				  << WHITE << ": " << RESET;
		std::getline(std::cin, zombieHordeName);

		// if user gives an input store the name and advance
		if (!zombieHordeName.empty()) {
			std::cout << CYAN << ">>> Name saved successfully <<<" << RESET << std::endl;
			std::cout << CYAN << "\n>>> Zombie names will be generated based on the horde name <<<" << RESET << std::endl;

			// await user input for horde size
			while (hordeSizeInput.empty()) {
				std::cout << PURPLE << "\nChoose a size for your zombie horde" 
				  << WHITE << ": " << RESET;
				std::getline(std::cin, hordeSizeInput);

				// if user gives an input and it is valid for the context store the value in an int and advance
				if (!hordeSizeInput.empty() && ft_customAtoi(hordeSizeInput) && ft_customAtoi(hordeSizeInput) < 2147483647 && ft_customAtoi(hordeSizeInput) > -2147483648) {
					int i = 0;
					hordeSize = ft_customAtoi(hordeSizeInput);
					std::srand(std::time(0));
					std::cout << CYAN << ">>> Size saved successfully <<<" << RESET << std::endl;
					std::cout << CYAN << "\n>>> Generating zombie horde with size "
							  << RED << hordeSize
							  << CYAN << "... <<<" << RESET << std::endl;
					std::cout << PURPLE << "\nLog"
								<< WHITE << ": " 
								<< PURPLE << "creating zombie horde..." << RESET << std::endl;
					zombies = zombieHorde(hordeSize, zombieHordeName);
					std::cout << CYAN << "\n\n>>> Zombie horde created <<<\n" << RESET << std::endl;
					for (i = 0; i < hordeSize; i++)
						zombies[i].announceRandomized();
					std::cout << CYAN "\n>>> Killing zombie horde <<<" << RESET << std::endl;
					delete[] zombies;
					std::cout << CYAN "\n>>> Zombie horde defeated <<<" << RESET << std::endl;
					return (0);
				}

				// if user gives an input but it is invalid for the context ask for a new input
				else if (!ft_customAtoi(hordeSizeInput) || ft_customAtoi(hordeSizeInput) >= 2147483647 || ft_customAtoi(hordeSizeInput) <= -2147483648) {
					std::cout << CLEAR_SCREEN;
					std::cout << RED << "\n------------------------------------------------------------------------!";
					std::cout << RED << "\nError"
				  			  << WHITE << ": "
				  			  << RED << "please insert a numeric only size value > 0 for your zombie horde"
				  			  << WHITE << ".\n" << RESET << std::endl;
					hordeSizeInput.clear();
				}

				// print empty input error for hordeSizeInput
				std::cout << CLEAR_SCREEN;
				std::cout << RED << "\n------------------------------------------------------------------------!";
				std::cout << RED << "\nError"
				  		  << WHITE << ": "
				  		  << RED << "please insert a numeric only size value > 0 for your zombie horde"
				  		  << WHITE << ".\n" << RESET << std::endl;
			}
		}
		
		// print empty input error for zombieHordeName
		std::cout << CLEAR_SCREEN;
		std::cout << RED << "\n-------------------------------------------------!";
		std::cout << RED << "\nError"
				  << WHITE << ": "
				  << RED << "please insert a name for your zombie horde"
				  << WHITE << ".\n" << RESET << std::endl;
	}
	
}