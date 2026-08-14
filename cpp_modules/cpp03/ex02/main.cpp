#include "FragTrap.hpp"

int main(void)
{
	std::cout << RED
		<< "\n==================================================\n"
		<< "                 FRAGTRAP TESTS\n"
		<< "==================================================\n"
		<< RESET;

	// =========================================================
	// BASIC CONSTRUCTION
	// =========================================================
	std::cout << RED
		<< "\n========== BASIC FRAGTRAP TEST ==========\n\n"
		<< RESET;

	FragTrap Frag("Frag");

	Frag.debug_func();

	// =========================================================
	// ATTACK
	// =========================================================
	std::cout << RED
		<< "\n========== ATTACK TEST ==========\n\n"
		<< RESET;

	Frag.attack("Bandit");
	Frag.debug_func();

	// =========================================================
	// HIGH FIVE
	// =========================================================
	std::cout << RED
		<< "\n========== HIGH FIVE TEST ==========\n\n"
		<< RESET;

	Frag.highFivesGuys();

	// =========================================================
	// DAMAGE / REPAIR
	// =========================================================
	std::cout << RED
		<< "\n========== DAMAGE / REPAIR TEST ==========\n\n"
		<< RESET;

	Frag.takeDamage(40);
	Frag.debug_func();

	Frag.beRepaired(20);
	Frag.debug_func();

	// =========================================================
	// DEATH
	// =========================================================
	std::cout << RED
		<< "\n========== DEATH TEST ==========\n\n"
		<< RESET;

	Frag.takeDamage(1000);
	Frag.debug_func();

	// Both should fail because Frag is dead
	Frag.attack("Bandit");
	Frag.beRepaired(10);

	// =========================================================
	// RESET
	// =========================================================
	std::cout << RED
		<< "\n========== RESET TEST ==========\n\n"
		<< RESET;

	Frag.reset();
	Frag.debug_func();

	// =========================================================
	// ENERGY
	// =========================================================
	std::cout << RED
		<< "\n========== ENERGY TEST ==========\n\n"
		<< RESET;

	// 100 energy points -> 100 attacks
	for (int i = 0; i < 100; i++)
		Frag.attack("Bandit");

	Frag.debug_func();

	// Should fail because energy is 0
	Frag.attack("Bandit");

	// Should also fail because energy is 0
	Frag.beRepaired(10);

	// =========================================================
	// COPY CONSTRUCTOR
	// =========================================================
	std::cout << RED
		<< "\n========== COPY CONSTRUCTOR TEST ==========\n\n"
		<< RESET;

	FragTrap Original("Original");

	Original.takeDamage(25);
	Original.attack("Bandit");

	std::cout << "Creating Copy from Original...\n";

	FragTrap Copy(Original);

	std::cout << "\nOriginal:\n";
	Original.debug_func();

	std::cout << "Copy:\n";
	Copy.debug_func();

	// =========================================================
	// ASSIGNMENT OPERATOR
	// =========================================================
	std::cout << RED
		<< "\n========== ASSIGNMENT OPERATOR TEST ==========\n\n"
		<< RESET;

	FragTrap Assigned("Assigned");

	std::cout << "Before assignment:\n";
	Assigned.debug_func();

	Assigned = Original;

	std::cout << "After assignment:\n";
	Assigned.debug_func();

	// =========================================================
	// SELF ASSIGNMENT
	// =========================================================
	std::cout << RED
		<< "\n========== SELF ASSIGNMENT TEST ==========\n\n"
		<< RESET;

	Assigned = Assigned;

	Assigned.debug_func();

	// =========================================================
	// DESTRUCTOR / CHAINING
	// =========================================================
	std::cout << RED
		<< "\n========== DESTRUCTOR / CHAINING TEST ==========\n\n"
		<< RESET;

	{
		FragTrap Temporary("TemporaryFrag");

		Temporary.highFivesGuys();
	}

	std::cout << RED
		<< "\n==================================================\n"
		<< "                    END TESTS\n"
		<< "==================================================\n\n"
		<< RESET;

	return (0);
}
