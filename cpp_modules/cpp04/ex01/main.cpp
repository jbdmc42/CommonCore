#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << RED
		<< "\n==================================================\n"
		<< "                  CPP04 EX01 TESTS\n"
		<< "==================================================\n"
		<< RESET;

	// =========================================================
	// BASIC CONSTRUCTION
	// =========================================================
	std::cout << RED
		<< "\n========== BASIC CONSTRUCTION ==========\n\n"
		<< RESET;

	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << "\nTypes:\n";
	std::cout << "Animal: " << animal.getType() << std::endl;
	std::cout << "Dog:    " << dog.getType() << std::endl;
	std::cout << "Cat:    " << cat.getType() << std::endl;


	// =========================================================
	// MAKE SOUND
	// =========================================================
	std::cout << RED
		<< "\n========== MAKE SOUND TEST ==========\n\n"
		<< RESET;

	std::cout << "Animal:\n";
	animal.makeSound();

	std::cout << "\nDog:\n";
	dog.makeSound();

	std::cout << "\nCat:\n";
	cat.makeSound();


	// =========================================================
	// BRAIN CONSTRUCTION
	// =========================================================
	std::cout << RED
		<< "\n========== BRAIN TEST ==========\n\n"
		<< RESET;

	std::cout << "Dog Brain address: " << dog.getBrain() << std::endl;
	std::cout << "Cat Brain address: " << cat.getBrain() << std::endl;

	std::cout << "\nFirst Dog idea:\n";
	std::cout << dog.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "\nLast Dog idea:\n";
	std::cout << dog.getBrain()->getIdeas()[99] << std::endl;


	// =========================================================
	// COPY CONSTRUCTOR
	// =========================================================
	std::cout << RED
		<< "\n========== COPY CONSTRUCTOR TEST ==========\n\n"
		<< RESET;

	std::cout << "Copying Animal...\n";
	Animal animalCopy(animal);

	std::cout << "Copying Dog...\n";
	Dog dogCopy(dog);

	std::cout << "Copying Cat...\n";
	Cat catCopy(cat);

	std::cout << "\nCopied types:\n";
	std::cout << "Animal copy: " << animalCopy.getType() << std::endl;
	std::cout << "Dog copy:    " << dogCopy.getType() << std::endl;
	std::cout << "Cat copy:    " << catCopy.getType() << std::endl;

	std::cout << "\nBrain addresses:\n";
	std::cout << "Original Dog Brain: " << dog.getBrain() << std::endl;
	std::cout << "Copied Dog Brain:   " << dogCopy.getBrain() << std::endl;

	std::cout << "\nOriginal Cat Brain: " << cat.getBrain() << std::endl;
	std::cout << "Copied Cat Brain:   " << catCopy.getBrain() << std::endl;


	// =========================================================
	// DEEP COPY - COPY CONSTRUCTOR
	// =========================================================
	std::cout << RED
		<< "\n========== DEEP COPY TEST ==========\n\n"
		<< RESET;

	dog.getBrain()->getIdeas()[0] = "Original Dog Idea";
	dogCopy.getBrain()->getIdeas()[0] = "Copied Dog Idea";

	std::cout << "Original Dog idea:\n";
	std::cout << dog.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "\nCopied Dog idea:\n";
	std::cout << dogCopy.getBrain()->getIdeas()[0] << std::endl;

	if (dog.getBrain()->getIdeas()[0]
		!= dogCopy.getBrain()->getIdeas()[0])
	{
		std::cout << "\nSUCCESS: Dog copy has an independent Brain.\n";
	}
	else
	{
		std::cout << "\nERROR: Dog copy shares Brain data!\n";
	}

	cat.getBrain()->getIdeas()[0] = "Original Cat Idea";
	catCopy.getBrain()->getIdeas()[0] = "Copied Cat Idea";

	std::cout << "\nOriginal Cat idea:\n";
	std::cout << cat.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "\nCopied Cat idea:\n";
	std::cout << catCopy.getBrain()->getIdeas()[0] << std::endl;

	if (cat.getBrain()->getIdeas()[0]
		!= catCopy.getBrain()->getIdeas()[0])
	{
		std::cout << "\nSUCCESS: Cat copy has an independent Brain.\n";
	}
	else
	{
		std::cout << "\nERROR: Cat copy shares Brain data!\n";
	}


	// =========================================================
	// ASSIGNMENT OPERATOR
	// =========================================================
	std::cout << RED
		<< "\n========== ASSIGNMENT OPERATOR TEST ==========\n\n"
		<< RESET;

	Animal animalAssigned;
	Dog dogAssigned;
	Cat catAssigned;

	animalAssigned = animal;
	dogAssigned = dog;
	catAssigned = cat;

	std::cout << "After assignment:\n";
	std::cout << "Animal: " << animalAssigned.getType() << std::endl;
	std::cout << "Dog:    " << dogAssigned.getType() << std::endl;
	std::cout << "Cat:    " << catAssigned.getType() << std::endl;


	// =========================================================
	// DEEP COPY - ASSIGNMENT
	// =========================================================
	std::cout << RED
		<< "\n========== ASSIGNMENT DEEP COPY TEST ==========\n\n"
		<< RESET;

	dog.getBrain()->getIdeas()[1] = "Assigned Dog Idea";
	dogAssigned = dog;

	dogAssigned.getBrain()->getIdeas()[1] = "Modified Assigned Dog Idea";

	std::cout << "Original Dog idea:\n";
	std::cout << dog.getBrain()->getIdeas()[1] << std::endl;

	std::cout << "\nAssigned Dog idea:\n";
	std::cout << dogAssigned.getBrain()->getIdeas()[1] << std::endl;

	if (dog.getBrain()->getIdeas()[1]
		!= dogAssigned.getBrain()->getIdeas()[1])
	{
		std::cout << "\nSUCCESS: Dog assignment is a deep copy.\n";
	}
	else
	{
		std::cout << "\nERROR: Dog assignment shares Brain data!\n";
	}

	cat.getBrain()->getIdeas()[1] = "Assigned Cat Idea";
	catAssigned = cat;

	catAssigned.getBrain()->getIdeas()[1] = "Modified Assigned Cat Idea";

	std::cout << "\nOriginal Cat idea:\n";
	std::cout << cat.getBrain()->getIdeas()[1] << std::endl;

	std::cout << "\nAssigned Cat idea:\n";
	std::cout << catAssigned.getBrain()->getIdeas()[1] << std::endl;

	if (cat.getBrain()->getIdeas()[1]
		!= catAssigned.getBrain()->getIdeas()[1])
	{
		std::cout << "\nSUCCESS: Cat assignment is a deep copy.\n";
	}
	else
	{
		std::cout << "\nERROR: Cat assignment shares Brain data!\n";
	}


	// =========================================================
	// SELF ASSIGNMENT
	// =========================================================
	std::cout << RED
		<< "\n========== SELF ASSIGNMENT TEST ==========\n\n"
		<< RESET;

	dog = dog;
	cat = cat;
	animal = animal;

	std::cout << "Self-assignment completed successfully.\n";

	std::cout << "\nTypes after self-assignment:\n";
	std::cout << "Animal: " << animal.getType() << std::endl;
	std::cout << "Dog:    " << dog.getType() << std::endl;
	std::cout << "Cat:    " << cat.getType() << std::endl;


	// =========================================================
	// POLYMORPHISM
	// =========================================================
	std::cout << RED
		<< "\n========== POLYMORPHISM TEST ==========\n\n"
		<< RESET;

	Animal *animalPtr;

	animalPtr = &animal;

	std::cout << "Animal pointer -> Animal:\n";
	std::cout << "Type: " << animalPtr->getType() << std::endl;
	animalPtr->makeSound();

	animalPtr = &dog;

	std::cout << "\nAnimal pointer -> Dog:\n";
	std::cout << "Type: " << animalPtr->getType() << std::endl;
	animalPtr->makeSound();

	animalPtr = &cat;

	std::cout << "\nAnimal pointer -> Cat:\n";
	std::cout << "Type: " << animalPtr->getType() << std::endl;
	animalPtr->makeSound();


	// =========================================================
	// ANIMAL ARRAY
	// =========================================================
	std::cout << RED
		<< "\n========== ANIMAL ARRAY TEST ==========\n\n"
		<< RESET;

	const int SIZE = 10;
	Animal *animals[SIZE];

	std::cout << "Creating 5 Dogs and 5 Cats...\n\n";

	for (int i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog();

	for (int i = SIZE / 2; i < SIZE; i++)
		animals[i] = new Cat();

	std::cout << "Testing every Animal in the array:\n\n";

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Animal [" << i << "] -> "
				  << animals[i]->getType() << ": ";

		animals[i]->makeSound();
	}


	// =========================================================
	// DELETE AS ANIMALS
	// =========================================================
	std::cout << RED
		<< "\n========== DELETE AS ANIMAL TEST ==========\n\n"
		<< RESET;

	std::cout << "Deleting every Animal through Animal pointers...\n\n";

	for (int i = 0; i < SIZE; i++)
	{
		delete animals[i];
		animals[i] = NULL;
	}

	std::cout << "\nAll Animals deleted.\n";


	// =========================================================
	// DESTRUCTOR / CHAINING TEST
	// =========================================================
	std::cout << RED
		<< "\n========== DESTRUCTOR / CHAINING TEST ==========\n\n"
		<< RESET;

	{
		std::cout << "Creating temporary Dog...\n\n";
		Dog temporaryDog;

		std::cout << "\nCreating temporary Cat...\n\n";
		Cat temporaryCat;

		std::cout << "\nLeaving scope...\n";
	}

	std::cout << RED
		<< "\n==================================================\n"
		<< "                    END TESTS\n"
		<< "==================================================\n\n"
		<< RESET;

	return 0;
}