#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << RED
		<< "\n==================================================\n"
		<< "                DIAMONDTRAP TESTS\n"
		<< "==================================================\n"
		<< RESET;

	// =========================================================
	// BASIC CONSTRUCTION
	// =========================================================
	std::cout << RED
		<< "\n========== BASIC DIAMONDTRAP TEST ==========\n\n"
		<< RESET;

	DiamondTrap Diamond("Diamond");

	Diamond.debug_func();

	// =========================================================
	// WHO AM I
	// =========================================================
	std::cout << RED
		<< "\n========== WHO AM I TEST ==========\n\n"
		<< RESET;

	Diamond.whoAmI();

	// =========================================================
	// ATTACK
	// =========================================================
	std::cout << RED
		<< "\n========== ATTACK TEST ==========\n\n"
		<< RESET;

	Diamond.attack("Bandit");
	Diamond.debug_func();

	// =========================================================
	// DAMAGE / REPAIR
	// =========================================================
	std::cout << RED
		<< "\n========== DAMAGE / REPAIR TEST ==========\n\n"
		<< RESET;

	Diamond.takeDamage(40);
	Diamond.debug_func();

	Diamond.beRepaired(20);
	Diamond.debug_func();

	// =========================================================
	// RESET
	// =========================================================
	std::cout << RED
		<< "\n========== RESET TEST ==========\n\n"
		<< RESET;

	Diamond.reset();
	Diamond.debug_func();

	// =========================================================
	// DEATH
	// =========================================================
	std::cout << RED
		<< "\n========== DEATH TEST ==========\n\n"
		<< RESET;

	Diamond.takeDamage(1000);
	Diamond.debug_func();

	// Both should fail because DiamondTrap is dead
	Diamond.attack("Bandit");
	Diamond.beRepaired(10);

	// =========================================================
	// RESET AFTER DEATH
	// =========================================================
	std::cout << RED
		<< "\n========== RESET AFTER DEATH TEST ==========\n\n"
		<< RESET;

	Diamond.reset();
	Diamond.debug_func();

	// =========================================================
	// ENERGY TEST
	// =========================================================
	std::cout << RED
		<< "\n========== ENERGY TEST ==========\n\n"
		<< RESET;

	/*
	 * DiamondTrap uses ScavTrap's energy value:
	 * 50 energy points.
	 *
	 * Therefore 50 attacks should reduce energy to 0.
	 */

	for (int i = 0; i < 50; i++)
		Diamond.attack("Bandit");

	Diamond.debug_func();

	// Should fail because energy is 0
	Diamond.attack("Bandit");

	// Should also fail because energy is 0
	Diamond.beRepaired(10);

	// =========================================================
	// HIGH FIVE TEST
	// =========================================================
	std::cout << RED
		<< "\n========== HIGH FIVE TEST ==========\n\n"
		<< RESET;

	Diamond.highFivesGuys();

	// =========================================================
	// GUARD GATE TEST
	// =========================================================
	std::cout << RED
		<< "\n========== GUARD GATE TEST ==========\n\n"
		<< RESET;

	Diamond.guardGate();

	// =========================================================
	// COPY CONSTRUCTOR
	// =========================================================
	std::cout << RED
		<< "\n========== COPY CONSTRUCTOR TEST ==========\n\n"
		<< RESET;

	DiamondTrap Original("Original");

	Original.takeDamage(25);
	Original.attack("Bandit");

	std::cout << "Creating Copy from Original...\n\n";

	DiamondTrap Copy(Original);

	std::cout << "Original:\n";
	Original.debug_func();

	std::cout << "Copy:\n";
	Copy.debug_func();

	std::cout << "\nOriginal names:\n";
	Original.whoAmI();

	std::cout << "\nCopy names:\n";
	Copy.whoAmI();

	// =========================================================
	// ASSIGNMENT OPERATOR
	// =========================================================
	std::cout << RED
		<< "\n========== ASSIGNMENT OPERATOR TEST ==========\n\n"
		<< RESET;

	DiamondTrap Assigned("Assigned");

	std::cout << "Before assignment:\n";
	Assigned.debug_func();

	Assigned.whoAmI();

	Assigned = Original;

	std::cout << "\nAfter assignment:\n";
	Assigned.debug_func();

	Assigned.whoAmI();

	// =========================================================
	// SELF ASSIGNMENT
	// =========================================================
	std::cout << RED
		<< "\n========== SELF ASSIGNMENT TEST ==========\n\n"
		<< RESET;

	Assigned = Assigned;

	Assigned.debug_func();
	Assigned.whoAmI();

	// =========================================================
	// DEFAULT CONSTRUCTOR
	// =========================================================
	std::cout << RED
		<< "\n========== DEFAULT CONSTRUCTOR TEST ==========\n\n"
		<< RESET;

	DiamondTrap Default;

	Default.debug_func();
	Default.whoAmI();

	// =========================================================
	// CONSTRUCTION / DESTRUCTION CHAINING
	// =========================================================
	std::cout << RED
		<< "\n========== DESTRUCTOR / CHAINING TEST ==========\n\n"
		<< RESET;

	{
		DiamondTrap Temporary("Temporary");

		Temporary.whoAmI();
		Temporary.attack("Bandit");
	}

	/*
	 * Expected destruction order:
	 *
	 * DiamondTrap
	 * FragTrap
	 * ScavTrap
	 * ClapTrap
	 *
	 * ClapTrap should appear ONLY ONCE.
	 */

	std::cout << RED
		<< "\n==================================================\n"
		<< "                    END TESTS\n"
		<< "==================================================\n\n"
		<< RESET;

	return (0);
}