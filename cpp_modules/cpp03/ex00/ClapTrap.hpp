#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
		unsigned int	svHitPoints;
		unsigned int	svEnergyPoints;

	public:
		// Constructor/Destructor
		ClapTrap( void );
		ClapTrap( std::string CTName );
		ClapTrap( const ClapTrap& other);
		ClapTrap& operator=( const ClapTrap& other);
		~ClapTrap( void );

		void	debug_func( void ) const;
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
		void	reset( void );
};

#endif