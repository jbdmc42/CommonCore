#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap Sheriff = ClapTrap("Sheriff");		// create claptrap
	Sheriff.debug_func();		// first show of claptrap stats

	Sheriff.attack("Bandit");	// attack: -1 energy
	Sheriff.debug_func();

	Sheriff.takeDamage(100);	// takes damage: 10HP - 100Dmg = 0HP 
	Sheriff.debug_func();

	Sheriff.attack("Bandit");	// tries to attack while dead: rejected
	Sheriff.debug_func();

	Sheriff.beRepaired(1);		// tries to repair itself while dead: rejected
	Sheriff.debug_func();

	Sheriff.reset();			// reset claptrap to its original state
	Sheriff.debug_func();

	for (int i = 0; i < 6; i++) {
		Sheriff.attack("Bandit");
		Sheriff.takeDamage(1);
		Sheriff.beRepaired(1);
		Sheriff.debug_func();
	}

	return(0);
}