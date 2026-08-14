#include "FragTrap.hpp"

FragTrap::FragTrap()
:	ClapTrap("Default", 100, 100, 30)
{
	std::cout << RED << "FragTrap" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

FragTrap::FragTrap(std::string CTName)
:	ClapTrap(CTName, 100, 100, 30)
{
	std::cout << RED << "FragTrap" << BROWNISH << " Constructor called." << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
:	ClapTrap(other)
{
	std::cout << RED << "FragTrap" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (hitPoints == 0)
	{
		std::cout << BROWNISH << "FragTrap " << RED << name << BROWNISH << " cannot attack because it is already dead." << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << BROWNISH << "FragTrap " << RED << name << BROWNISH << " cannot attack because it has no more energy left." << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << BROWNISH << "FragTrap " << RED << name << BROWNISH << " attacks " << RED << target << BROWNISH << ", causing " << RED << attackDamage << BROWNISH << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << BROWNISH << "FragTrap " << RED << name << BROWNISH << " is asking for high-fives!" << RESET << std::endl;
}