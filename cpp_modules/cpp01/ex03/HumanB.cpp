#include "HumanB.hpp"

HumanB::HumanB(std::string name ) : weapon(NULL), name(name) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack() const {
	if (this->weapon)
		std::cout << "\n --> " << RED << this->name << PURPLE << " attacks with their " << RED << this->weapon->getType() << WHITE << "." << RESET << std::endl;
	else
		std::cout << "\n --> " << RED << this->name << PURPLE << " tries to attack but is unarmed" << WHITE << "!" << RESET << std::endl; 
}