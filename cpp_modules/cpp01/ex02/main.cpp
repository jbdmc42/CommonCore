#include <iostream>
#include <string>

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"
#define CLEAR_SCREEN "\033[2J\033[H"

int	main(void) {

	// 1. initialize the 3 variables as requested
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	// 2. print memory addresses
	std::cout << PURPLE << "=============== MEMORY ADDRESSES ===============>" << RESET << std::endl;
	std::cout << PURPLE << "Address of the 'string' variable" << WHITE << ": " << RED << &string << RESET << std::endl;
	std::cout << PURPLE << "Address held by 'stringPTR'" << WHITE << ": " << RED << stringPTR << RESET << std::endl;
	std::cout << PURPLE << "Address held by 'stringREF'" << WHITE << ": " << RED << &stringREF << RESET << std::endl;

	// 3. print values
	std::cout << PURPLE << "\n\n=============== VARIABLES VALUES ===============>" << RESET << std::endl;
	std::cout << PURPLE << "Value of the 'string' variable" << WHITE << ": " << RED << string << RESET << std::endl;
	std::cout << PURPLE << "Value pointed to 'stringPTR'" << WHITE << ": " << RED << *stringPTR << RESET << std::endl;
	std::cout << PURPLE << "Value pointed to 'stringREF'" << WHITE << ": " << RED << stringREF << RESET << std::endl;

	return (0);
}