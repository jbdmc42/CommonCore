#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
:	type("WrongAnimal")
{
	std::cout << RED << "WrongAnimal" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string AT)
:	type(AT)
{
	std::cout << RED << "WrongAnimal" << BROWNISH << " Constructor called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
:	type(other.type)
{
	std::cout << RED << "WrongAnimal" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << RED << "*criket sound intensifies*" << RESET << std::endl;
}

const std::string& WrongAnimal::getType() const {
	return this->type;
}