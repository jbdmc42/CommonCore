#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << RED
		<< "\n==================================================\n"
		<< "                  CPP04 EX00 TESTS\n"
		<< "==================================================\n"
		<< RESET;

	// =========================================================
	// BASIC CONSTRUCTION
	// =========================================================
	std::cout << RED
		<< "\n========== BASIC CONSTRUCTION ==========\n\n"
		<< RESET;

	Animal AnimalObj;
	Dog DogObj;
	Cat CatObj;

	std::cout << "\nTypes:\n";
	std::cout << "Animal: " << AnimalObj.getType() << std::endl;
	std::cout << "Dog:    " << DogObj.getType() << std::endl;
	std::cout << "Cat:    " << CatObj.getType() << std::endl;


	// =========================================================
	// BASIC MAKE SOUND
	// =========================================================
	std::cout << RED
		<< "\n========== BASIC MAKE SOUND ==========\n\n"
		<< RESET;

	std::cout << "Animal:\n";
	AnimalObj.makeSound();

	std::cout << "\nDog:\n";
	DogObj.makeSound();

	std::cout << "\nCat:\n";
	CatObj.makeSound();


	// =========================================================
	// COPY CONSTRUCTORS
	// =========================================================
	std::cout << RED
		<< "\n========== COPY CONSTRUCTOR TEST ==========\n\n"
		<< RESET;

	std::cout << "Copying Animal...\n";
	Animal AnimalCopy(AnimalObj);

	std::cout << "\nCopying Dog...\n";
	Dog DogCopy(DogObj);

	std::cout << "\nCopying Cat...\n";
	Cat CatCopy(CatObj);

	std::cout << "\nCopied types:\n";
	std::cout << "Animal copy: " << AnimalCopy.getType() << std::endl;
	std::cout << "Dog copy:    " << DogCopy.getType() << std::endl;
	std::cout << "Cat copy:    " << CatCopy.getType() << std::endl;


	// =========================================================
	// ASSIGNMENT OPERATORS
	// =========================================================
	std::cout << RED
		<< "\n========== ASSIGNMENT OPERATOR TEST ==========\n\n"
		<< RESET;

	Animal AnimalAssigned;
	Dog DogAssigned;
	Cat CatAssigned;

	AnimalAssigned = AnimalObj;
	DogAssigned = DogObj;
	CatAssigned = CatObj;

	std::cout << "After assignment:\n";
	std::cout << "Animal: " << AnimalAssigned.getType() << std::endl;
	std::cout << "Dog:    " << DogAssigned.getType() << std::endl;
	std::cout << "Cat:    " << CatAssigned.getType() << std::endl;


	// =========================================================
	// SELF ASSIGNMENT
	// =========================================================
	std::cout << RED
		<< "\n========== SELF ASSIGNMENT TEST ==========\n\n"
		<< RESET;

	AnimalAssigned = AnimalAssigned;
	DogAssigned = DogAssigned;
	CatAssigned = CatAssigned;

	std::cout << "Self-assignment completed.\n";

	std::cout << "Types after self-assignment:\n";
	std::cout << "Animal: " << AnimalAssigned.getType() << std::endl;
	std::cout << "Dog:    " << DogAssigned.getType() << std::endl;
	std::cout << "Cat:    " << CatAssigned.getType() << std::endl;


	// =========================================================
	// POLYMORPHISM - STACK OBJECTS
	// =========================================================
	std::cout << RED
		<< "\n========== POLYMORPHISM TEST ==========\n\n"
		<< RESET;

	Animal *AnimalPtr;

	std::cout << "Animal pointer -> Animal:\n";
	AnimalPtr = &AnimalObj;
	std::cout << "Type: " << AnimalPtr->getType() << std::endl;
	AnimalPtr->makeSound();

	std::cout << "\nAnimal pointer -> Dog:\n";
	AnimalPtr = &DogObj;
	std::cout << "Type: " << AnimalPtr->getType() << std::endl;
	AnimalPtr->makeSound();

	std::cout << "\nAnimal pointer -> Cat:\n";
	AnimalPtr = &CatObj;
	std::cout << "Type: " << AnimalPtr->getType() << std::endl;
	AnimalPtr->makeSound();


	// =========================================================
	// POLYMORPHISM - HEAP OBJECTS
	// =========================================================
	std::cout << RED
		<< "\n========== HEAP POLYMORPHISM TEST ==========\n\n"
		<< RESET;

	Animal *DogPtr = new Dog();
	Animal *CatPtr = new Cat();

	std::cout << "Dog through Animal pointer:\n";
	std::cout << "Type: " << DogPtr->getType() << std::endl;
	DogPtr->makeSound();

	std::cout << "\nCat through Animal pointer:\n";
	std::cout << "Type: " << CatPtr->getType() << std::endl;
	CatPtr->makeSound();

	std::cout << "\nDeleting Dog through Animal pointer:\n";
	delete DogPtr;

	std::cout << "\nDeleting Cat through Animal pointer:\n";
	delete CatPtr;


	// =========================================================
	// WRONGANIMAL BASIC CONSTRUCTION
	// =========================================================
	std::cout << RED
		<< "\n========== WRONGANIMAL CONSTRUCTION ==========\n\n"
		<< RESET;

	WrongAnimal WrongAnimalObj;
	WrongCat WrongCatObj;

	std::cout << "\nTypes:\n";
	std::cout << "WrongAnimal: " << WrongAnimalObj.getType() << std::endl;
	std::cout << "WrongCat:    " << WrongCatObj.getType() << std::endl;


	// =========================================================
	// WRONGANIMAL BASIC MAKE SOUND
	// =========================================================
	std::cout << RED
		<< "\n========== WRONGANIMAL MAKE SOUND ==========\n\n"
		<< RESET;

	std::cout << "WrongAnimal:\n";
	WrongAnimalObj.makeSound();

	std::cout << "\nWrongCat:\n";
	WrongCatObj.makeSound();


	// =========================================================
	// WRONG COPY CONSTRUCTORS
	// =========================================================
	std::cout << RED
		<< "\n========== WRONG COPY CONSTRUCTOR TEST ==========\n\n"
		<< RESET;

	std::cout << "Copying WrongAnimal...\n";
	WrongAnimal WrongAnimalCopy(WrongAnimalObj);

	std::cout << "\nCopying WrongCat...\n";
	WrongCat WrongCatCopy(WrongCatObj);

	std::cout << "\nCopied types:\n";
	std::cout << "WrongAnimal copy: "
			  << WrongAnimalCopy.getType() << std::endl;

	std::cout << "WrongCat copy:    "
			  << WrongCatCopy.getType() << std::endl;


	// =========================================================
	// WRONG ASSIGNMENT OPERATORS
	// =========================================================
	std::cout << RED
		<< "\n========== WRONG ASSIGNMENT OPERATOR TEST ==========\n\n"
		<< RESET;

	WrongAnimal WrongAnimalAssigned;
	WrongCat WrongCatAssigned;

	WrongAnimalAssigned = WrongAnimalObj;
	WrongCatAssigned = WrongCatObj;

	std::cout << "After assignment:\n";
	std::cout << "WrongAnimal: "
			  << WrongAnimalAssigned.getType() << std::endl;

	std::cout << "WrongCat:    "
			  << WrongCatAssigned.getType() << std::endl;


	// =========================================================
	// WRONG SELF ASSIGNMENT
	// =========================================================
	std::cout << RED
		<< "\n========== WRONG SELF ASSIGNMENT TEST ==========\n\n"
		<< RESET;

	WrongAnimalAssigned = WrongAnimalAssigned;
	WrongCatAssigned = WrongCatAssigned;

	std::cout << "Self-assignment completed.\n";

	std::cout << "WrongAnimal: "
			  << WrongAnimalAssigned.getType() << std::endl;

	std::cout << "WrongCat:    "
			  << WrongCatAssigned.getType() << std::endl;


	// =========================================================
	// THE IMPORTANT WRONG POLYMORPHISM TEST
	// =========================================================
	std::cout << RED
		<< "\n========== WRONG POLYMORPHISM TEST ==========\n\n"
		<< RESET;

	WrongAnimal *WrongPtr;

	std::cout << "WrongAnimal pointer -> WrongAnimal:\n";
	WrongPtr = &WrongAnimalObj;
	std::cout << "Type: " << WrongPtr->getType() << std::endl;
	WrongPtr->makeSound();

	std::cout << "\nWrongAnimal pointer -> WrongCat:\n";
	WrongPtr = &WrongCatObj;
	std::cout << "Type: " << WrongPtr->getType() << std::endl;
	WrongPtr->makeSound();


	// =========================================================
	// CORRECT VS WRONG COMPARISON
	// =========================================================
	std::cout << RED
		<< "\n========== CORRECT VS WRONG COMPARISON ==========\n\n"
		<< RESET;

	Animal *Correct = &CatObj;
	WrongAnimal *Wrong = &WrongCatObj;

	std::cout << "Correct hierarchy:\n";
	std::cout << "Pointer type: Animal*\n";
	std::cout << "Object type:  " << Correct->getType() << std::endl;
	Correct->makeSound();

	std::cout << "\nWrong hierarchy:\n";
	std::cout << "Pointer type: WrongAnimal*\n";
	std::cout << "Object type:  " << Wrong->getType() << std::endl;
	Wrong->makeSound();


	// =========================================================
	// DESTRUCTOR / CHAINING TEST
	// =========================================================
	std::cout << RED
		<< "\n========== DESTRUCTOR / CHAINING TEST ==========\n\n"
		<< RESET;

	{
		std::cout << "Creating temporary Dog...\n\n";

		Dog TemporaryDog;

		std::cout << "\nCreating temporary Cat...\n\n";

		Cat TemporaryCat;

		std::cout << "\nCreating temporary WrongCat...\n\n";

		WrongCat TemporaryWrongCat;

		std::cout << "\nLeaving scope...\n";
	}

	std::cout << RED
		<< "\n==================================================\n"
		<< "                    END TESTS\n"
		<< "==================================================\n\n"
		<< RESET;

	return (0);
}