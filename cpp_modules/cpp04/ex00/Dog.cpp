#include "Dog.hpp"

Dog::Dog()
:	Animal("Dog")
{
	std::cout << RED << "Dog" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

Dog::Dog(const Dog& other)
:	Animal(other)
{
	std::cout << RED << "Dog" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << RED << "Dog" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << RED << "Woof! Woof!" << RESET << std::endl;
}