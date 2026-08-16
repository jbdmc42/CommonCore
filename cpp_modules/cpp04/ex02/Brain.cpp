#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;

		ss << "Idea [" << (i + 1) << "]";
		ideas[i] = ss.str();
	}
	std::cout << RED << "Brain" << BROWNISH << " Constructor called." << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << RED << "Brain" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << RED << "Brain" << BROWNISH << " Destructor called." << RESET << std::endl;
}

std::string* Brain::getIdeas() {
	return this->ideas;
}
