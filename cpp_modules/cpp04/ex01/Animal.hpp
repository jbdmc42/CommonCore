#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal( void );
		Animal( std::string AT );
		Animal( const Animal& other );
		Animal& operator=( const Animal& other );
		virtual ~Animal( void );

		virtual void makeSound( void ) const;
		const std::string& getType( void ) const;
};

#endif