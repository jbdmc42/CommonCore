#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( std::string CTName );
		ScavTrap( const ScavTrap& other);
		ScavTrap& operator=( const ScavTrap& other);
		~ScavTrap( void );

		void	attack( const std::string& target );
		void	guardGate( void );
};

#endif