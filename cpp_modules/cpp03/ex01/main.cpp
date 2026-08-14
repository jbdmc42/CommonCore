#include "ScavTrap.hpp"

int main(void)
{
	std::cout << RED << "\n========== BASIC SCAVTRAP TEST ==========\n\n";

	ScavTrap Sheriff("Sheriff");

	Sheriff.debug_func();

	std::cout << RED << "\n========== ATTACK TEST ==========\n\n";

	Sheriff.attack("Bandit");
	Sheriff.debug_func();

	std::cout << RED << "\n========== GUARD GATE TEST ==========\n\n";

	Sheriff.guardGate();

	std::cout << RED << "\n========== DAMAGE / REPAIR TEST ==========\n\n";

	Sheriff.takeDamage(30);
	Sheriff.debug_func();

	Sheriff.beRepaired(10);
	Sheriff.debug_func();

	std::cout << RED << "\n========== DEATH TEST ==========\n\n";

	Sheriff.takeDamage(1000);
	Sheriff.debug_func();

	Sheriff.attack("Bandit");
	Sheriff.beRepaired(10);

	std::cout << RED << "\n========== RESET TEST ==========\n\n";

	Sheriff.reset();
	Sheriff.debug_func();

	std::cout << RED << "\n========== ENERGY TEST ==========\n\n";

	for (int i = 0; i < 50; i++)
		Sheriff.attack("Bandit");

	Sheriff.debug_func();

	// Should fail because energy is 0
	Sheriff.attack("Bandit");

	// Should also fail because energy is 0
	Sheriff.beRepaired(10);

	std::cout << RED << "\n========== COPY CONSTRUCTOR TEST ==========\n\n";

	ScavTrap Original("Original");

	Original.takeDamage(25);
	Original.attack("Bandit");

	ScavTrap Copy(Original);

	Copy.debug_func();

	std::cout << RED << "\n========== ASSIGNMENT OPERATOR TEST ==========\n\n";

	ScavTrap Assigned("Assigned");

	Assigned.debug_func();

	Assigned = Original;

	Assigned.debug_func();

	std::cout << RED << "\n========== SELF ASSIGNMENT TEST ==========\n\n";

	Assigned = Assigned;

	Assigned.debug_func();

	std::cout << RED << "\n========== DESTRUCTOR / CHAINING TEST ==========\n\n";

	{
		ScavTrap Temporary("Temporary");
		Temporary.guardGate();
	}

	std::cout << RED << "\n========== END ==========\n\n";

	return (0);
}