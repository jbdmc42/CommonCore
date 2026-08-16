#ifndef BRAIN_HPP
#define BRAIN_HPP

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"

#include <iostream>
#include <string>
#include <sstream>

class Brain {
	private:
		std::string	ideas[100];
	public:
		Brain( void );
		Brain( const Brain& other );
		Brain& operator=( const Brain& other );
		virtual ~Brain( void );

		std::string* getIdeas( void );
};

#endif