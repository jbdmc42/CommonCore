#include "WrongCat.hpp"

WrongCat::WrongCat()
:	WrongAnimal("WrongCat")
{
	std::cout << RED << "WrongCat" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
:	WrongAnimal(other)
{
	std::cout << RED << "WrongCat" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << RED << "Meow! Meow!" << RESET << std::endl;
}