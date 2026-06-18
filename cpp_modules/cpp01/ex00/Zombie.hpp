#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	name;							// zombie name

	public:
		Zombie( std::string );						// constructor
		~Zombie( void );							// destructor

		void	announce( void );					// zombie announces itself as follows: "<name>: BraiiiiiiinnnzzzZ..."
};

Zombie* newZombie( std::string name );				// create a new zombie object, naming it and returning it so it can be used outside its scope
void 	randomChump( std::string name );			// create a new zombie object, naming it and making it announce itself (use announce())

#endif