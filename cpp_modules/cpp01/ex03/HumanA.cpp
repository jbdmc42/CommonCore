#include "HumanA.hpp"

HumanA::HumanA(Weapon& weapon, std::string name ) : weapon(weapon), name(name) {}

HumanA::~HumanA() {}

void	HumanA::attack() const {
	std::cout << "\n --> " << RED << this->name << PURPLE << " attacks with their " << RED << this->weapon.getType() << WHITE << "." << RESET << std::endl; 
}