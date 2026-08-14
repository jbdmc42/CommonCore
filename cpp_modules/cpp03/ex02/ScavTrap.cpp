#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
:	ClapTrap("Default", 100, 50, 20)
{
	std::cout << RED << "ScavTrap" << BROWNISH << " Default Constructor called." << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string CTName)
:	ClapTrap(CTName, 100, 50, 20)
{
	std::cout << RED << "ScavTrap" << BROWNISH << " Constructor called." << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
:	ClapTrap(other)
{
	std::cout << RED << "ScavTrap" << BROWNISH << " Copy Constructor called." << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "ScavTrap" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (hitPoints == 0)
	{
		std::cout << BROWNISH << "ScavTrap " << RED << name << BROWNISH << " cannot attack because it is already dead." << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << BROWNISH << "ScavTrap " << RED << name << BROWNISH << " cannot attack because it has no more energy left." << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << BROWNISH << "ScavTrap " << RED << name << BROWNISH << " attacks " << RED << target << BROWNISH << ", causing " << RED << attackDamage << BROWNISH << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << BROWNISH << "ScavTrap " << RED << name << BROWNISH << " is now in Gate keeper mode." << RESET << std::endl;
}