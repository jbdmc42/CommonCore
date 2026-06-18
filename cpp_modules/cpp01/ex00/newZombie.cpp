#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* heapZombie = new Zombie(name);
	
	return (heapZombie);
}