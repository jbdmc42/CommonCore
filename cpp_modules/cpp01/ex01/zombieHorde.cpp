#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
	// 1. generate horde
	Zombie* horde = new Zombie[N];

	// 2. create zombies
	for (int i = 0; i < N; i++) {
		std::stringstream ss;
		ss << name << " " << (i + 1);
		horde[i].setName(ss.str());
	}

	return (horde);
}