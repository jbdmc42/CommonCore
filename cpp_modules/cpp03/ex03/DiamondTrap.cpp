#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
:	ClapTrap("Default_clap_name", 100, 50, 30),
	ScavTrap("Default"),
	FragTrap("Default"),
	name("Default")
{
	std::cout << RED << "DiamondTrap" << BROWNISH
			  << " Default Constructor called." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string CTName)
:	ClapTrap(CTName + "_clap_name", 100, 50, 30),
	ScavTrap(CTName),
	FragTrap(CTName),
	name(CTName)
{
	std::cout << RED << "DiamondTrap" << BROWNISH
			  << " Constructor called." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
:	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	name(other.name)
{
	std::cout << RED << "DiamondTrap" << BROWNISH
			  << " Copy Constructor called." << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}

	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap" << BROWNISH
			  << " Destructor called." << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << BROWNISH << "My name is " << RED << name << RESET << std::endl;
	std::cout << BROWNISH << "My ClapTrap name is " << RED << ClapTrap::name << RESET << std::endl;
}
