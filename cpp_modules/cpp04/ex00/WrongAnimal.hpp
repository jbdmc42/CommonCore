#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#define CYAN "\033[1;36m"
#define PURPLE "\033[1;35m"
#define BROWNISH "\033[1;33m"
#define RED "\033[1;31m"
#define WHITE "\033[1;0m"
#define RESET "\033[0m"

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string type;
	
	public:
		WrongAnimal(void);
		WrongAnimal(std::string WAT);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal(void);

		void makeSound(void) const;
		const std::string& getType(void) const;
};

#endif