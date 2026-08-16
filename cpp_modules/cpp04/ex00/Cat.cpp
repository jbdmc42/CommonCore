#include "Cat.hpp"

Cat::Cat()
:	Animal("Cat")
{
	std::cout << RED << "Cat" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

Cat::Cat(const Cat& other)
:	Animal(other)
{
	std::cout << RED << "Cat" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat() {
	std::cout << RED << "Cat" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void Cat::makeSound() const {
	std::cout << RED << "Meow! Meow!" << RESET << std::endl;
}