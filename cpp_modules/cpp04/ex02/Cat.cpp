#include "Cat.hpp"

Cat::Cat()
:	Animal("Cat"),
	brain(new Brain())
{
	std::cout << RED << "Cat" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

Cat::Cat(const Cat& other)
:	Animal(other),
	brain(new Brain(*other.brain))
{
	std::cout << RED << "Cat" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << RED << "Cat" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void Cat::makeSound() const {
	std::cout << RED << "Meow! Meow!" << RESET << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return brain;
}