#include "Animal.hpp"

Animal::Animal()
:	type("Animal")
{
	std::cout << RED << "Animal" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

Animal::Animal(std::string AT)
:	type(AT)
{
	std::cout << RED << "Animal" << BROWNISH << " Constructor called." << RESET << std::endl;
}

Animal::Animal(const Animal& other)
:	type(other.type)
{
	std::cout << RED << "Animal" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << RED << "Animal" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void Animal::makeSound() const {
	std::cout << RED << "*criket sound intensifies*" << RESET << std::endl;
}

const std::string& Animal::getType() const {
	return this->type;
}