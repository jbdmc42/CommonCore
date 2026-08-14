#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Default"),
      hitPoints(10),
      energyPoints(10),
      attackDamage(0),
      svHitPoints(10),
      svEnergyPoints(10)
{
    std::cout << RED << "ClapTrap" << BROWNISH
              << " Default Constructor called." << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string CTName)
    : name(CTName),
      hitPoints(10),
      energyPoints(10),
      attackDamage(0),
      svHitPoints(10),
      svEnergyPoints(10)
{
    std::cout << RED << "ClapTrap" << BROWNISH
              << " Constructor called." << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage),
      svHitPoints(other.svHitPoints),
      svEnergyPoints(other.svEnergyPoints)
{
    std::cout << RED << "ClapTrap" << BROWNISH
              << " Copy Constructor called." << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		svEnergyPoints = other.svEnergyPoints;
		svHitPoints = other.svHitPoints;
	}

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap" << BROWNISH << " Destructor called." << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints == 0)
	{
		std::cout << BROWNISH << "ClapTrap " << RED << name << BROWNISH << " cannot attack because it is already dead." << RESET << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << BROWNISH << "ClapTrap " << RED << name << BROWNISH << " cannot attack because it has no more energy left." << RESET << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << BROWNISH << "ClapTrap " << RED << name << BROWNISH << " attacks " << RED << target << BROWNISH << ", causing " << RED << attackDamage << BROWNISH << " points of damage!" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0)
	{
		std::cout << BROWNISH << "ClapTrap " << RED << name << BROWNISH << " cannot take any damage because it is already dead." << RESET << std::endl;
		return ;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << BROWNISH << "ClapTrap " << RED << name << BROWNISH << " has been damaged by " << RED << amount << BROWNISH << " hit points." << RESET << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints == 0)
	{
		std::cout << BROWNISH << "ClapTrap " << RED << name << BROWNISH << " cannot repair itself because it is already dead." << RESET << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << BROWNISH << "ClapTrap " << RED << name << BROWNISH << " cannot repair itself because it has no more energy left." << RESET << std::endl;
		return ;
	}
	hitPoints += amount;
	energyPoints--;
	std::cout << BROWNISH << "ClapTrap " << RED << name << BROWNISH << " has been repaired by " << RED << amount << BROWNISH << " hit points." << RESET << std::endl;
}

void	ClapTrap::debug_func() const {
	std::cout << PURPLE << "\nHit Points: " << CYAN << this->hitPoints << RESET << std::endl;
	std::cout << PURPLE << "Energy Points: " << CYAN << this->energyPoints << "\n" << RESET << std::endl;
}

void	ClapTrap::reset() {
	energyPoints = svEnergyPoints;
	hitPoints = svHitPoints;
	std::cout << BROWNISH << "ClapTrap "<< RED << name << BROWNISH << " was reset." << "\n" << RESET << std::endl;
}