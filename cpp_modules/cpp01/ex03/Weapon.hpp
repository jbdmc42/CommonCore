#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"
#define CLEAR_SCREEN "\033[2J\033[H"

class Weapon {
	private:
		std::string type;

	public:
		Weapon( std::string type );
		~Weapon( void );

		const std::string&	getType( void ) const ;
		void 				setType( std::string newType );
};

#endif