#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"
#define CLEAR_SCREEN "\033[2J\033[H"

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	name;							// zombie name

	public:
		Zombie( void );								// default constructor for the array
		Zombie( std::string );						// constructor
		~Zombie( void );							// destructor

		void	setName( std::string name );		// sets each zombie name
		void	announceRandomized( void );			// zombie announces itself with a random, pre-determined message
};

Zombie* 	zombieHorde( int N, std::string name );		// create an array of zombie objects, naming each and making each of them announce themselves (use announceRandomized()) 

#endif