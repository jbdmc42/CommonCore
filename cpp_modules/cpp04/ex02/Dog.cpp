#include "Dog.hpp"

Dog::Dog()
:	Animal("Dog"),
	brain(new Brain())
{
	std::cout << RED << "Dog" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

Dog::Dog(const Dog& other)
:	Animal(other),
	brain(new Brain(*other.brain))
{
	std::cout << RED << "Dog" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << RED << "Dog" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << RED << "Woof! Woof!" << RESET << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return brain;
}