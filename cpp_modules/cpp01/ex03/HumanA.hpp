#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"
#define CLEAR_SCREEN "\033[2J\033[H"

class HumanA {
	private:
		Weapon&		weapon;
		std::string name;

	public:
		HumanA( Weapon& weapon, std::string name );
		~HumanA( void );

		void				attack( void ) const;
};

#endif