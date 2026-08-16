#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	std::cout << RED
		<< "\n==================================================\n"
		<< "                  CPP04 EX02 TESTS\n"
		<< "==================================================\n"
		<< RESET;

	// =========================================================
	// BASIC CONSTRUCTION
	// =========================================================
	std::cout << RED
		<< "\n========== BASIC CONSTRUCTION ==========\n\n"
		<< RESET;

	Dog dog;
	Cat cat;

	std::cout << "\nTypes:\n";
	std::cout << "Dog:    " << dog.getType() << std::endl;
	std::cout << "Cat:    " << cat.getType() << std::endl;

	// =========================================================
	// MAKE SOUND TEST
	// =========================================================
	std::cout << RED
		<< "\n========== MAKE SOUND TEST ==========\n\n"
		<< RESET;

	std::cout << "Dog:\n";
	dog.makeSound();

	std::cout << "\nCat:\n";
	cat.makeSound();

	// =========================================================
	// BRAIN TEST
	// =========================================================
	std::cout << RED
		<< "\n========== BRAIN TEST ==========\n\n"
		<< RESET;

	std::cout << "Dog Brain address: " << dog.getBrain() << std::endl;
	std::cout << "Cat Brain address: " << cat.getBrain() << std::endl;

	dog.getBrain()->getIdeas()[0] = "Dog Idea";
	cat.getBrain()->getIdeas()[0] = "Cat Idea";

	std::cout << "\nDog first idea:\n";
	std::cout << dog.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "\nCat first idea:\n";
	std::cout << cat.getBrain()->getIdeas()[0] << std::endl;

	// =========================================================
	// COPY CONSTRUCTOR TEST
	// =========================================================
	std::cout << RED
		<< "\n========== COPY CONSTRUCTOR TEST ==========\n\n"
		<< RESET;

	std::cout << "Copying Dog...\n";
	Dog dogCopy(dog);

	std::cout << "Copying Cat...\n";
	Cat catCopy(cat);

	std::cout << "\nCopied types:\n";
	std::cout << "Dog copy: " << dogCopy.getType() << std::endl;
	std::cout << "Cat copy: " << catCopy.getType() << std::endl;

	std::cout << "\nBrain addresses:\n";
	std::cout << "Original Dog Brain: " << dog.getBrain() << std::endl;
	std::cout << "Copied Dog Brain:   " << dogCopy.getBrain() << std::endl;

	std::cout << "\nOriginal Cat Brain: " << cat.getBrain() << std::endl;
	std::cout << "Copied Cat Brain:   " << catCopy.getBrain() << std::endl;

	// =========================================================
	// DEEP COPY TEST
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
		!= dogCopy.getBrain()->getIdeas()[0]
		&& dog.getBrain() != dogCopy.getBrain())
		std::cout << "\nSUCCESS: Dog copy has an independent Brain.\n";

	cat.getBrain()->getIdeas()[0] = "Original Cat Idea";
	catCopy.getBrain()->getIdeas()[0] = "Copied Cat Idea";

	std::cout << "\nOriginal Cat idea:\n";
	std::cout << cat.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "\nCopied Cat idea:\n";
	std::cout << catCopy.getBrain()->getIdeas()[0] << std::endl;

	if (cat.getBrain()->getIdeas()[0]
		!= catCopy.getBrain()->getIdeas()[0]
		&& cat.getBrain() != catCopy.getBrain())
		std::cout << "\nSUCCESS: Cat copy has an independent Brain.\n";

	// =========================================================
	// ASSIGNMENT OPERATOR TEST
	// =========================================================
	std::cout << RED
		<< "\n========== ASSIGNMENT OPERATOR TEST ==========\n\n"
		<< RESET;

	Dog assignedDog;
	Cat assignedCat;

	assignedDog = dog;
	assignedCat = cat;

	std::cout << "After assignment:\n";
	std::cout << "Dog: " << assignedDog.getType() << std::endl;
	std::cout << "Cat: " << assignedCat.getType() << std::endl;

	// =========================================================
	// ASSIGNMENT DEEP COPY TEST
	// =========================================================
	std::cout << RED
		<< "\n========== ASSIGNMENT DEEP COPY TEST ==========\n\n"
		<< RESET;

	assignedDog.getBrain()->getIdeas()[0] = "Assigned Dog Idea";

	std::cout << "Original Dog idea:\n";
	std::cout << dog.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "\nAssigned Dog idea:\n";
	std::cout << assignedDog.getBrain()->getIdeas()[0] << std::endl;

	if (dog.getBrain()->getIdeas()[0]
		!= assignedDog.getBrain()->getIdeas()[0]
		&& dog.getBrain() != assignedDog.getBrain())
		std::cout << "\nSUCCESS: Dog assignment is a deep copy.\n";

	assignedCat.getBrain()->getIdeas()[0] = "Assigned Cat Idea";

	std::cout << "\nOriginal Cat idea:\n";
	std::cout << cat.getBrain()->getIdeas()[0] << std::endl;

	std::cout << "\nAssigned Cat idea:\n";
	std::cout << assignedCat.getBrain()->getIdeas()[0] << std::endl;

	if (cat.getBrain()->getIdeas()[0]
		!= assignedCat.getBrain()->getIdeas()[0]
		&& cat.getBrain() != assignedCat.getBrain())
		std::cout << "\nSUCCESS: Cat assignment is a deep copy.\n";

	// =========================================================
	// SELF ASSIGNMENT TEST
	// =========================================================
	std::cout << RED
		<< "\n========== SELF ASSIGNMENT TEST ==========\n\n"
		<< RESET;

	dog = dog;
	cat = cat;

	std::cout << "Self-assignment completed successfully.\n";

	std::cout << "\nTypes after self-assignment:\n";
	std::cout << "Dog: " << dog.getType() << std::endl;
	std::cout << "Cat: " << cat.getType() << std::endl;

	// =========================================================
	// POLYMORPHISM TEST
	// =========================================================
	std::cout << RED
		<< "\n========== POLYMORPHISM TEST ==========\n\n"
		<< RESET;

	Animal *animalDog = &dog;
	Animal *animalCat = &cat;

	std::cout << "Animal pointer -> Dog:\n";
	std::cout << "Type: " << animalDog->getType() << std::endl;
	animalDog->makeSound();

	std::cout << "\nAnimal pointer -> Cat:\n";
	std::cout << "Type: " << animalCat->getType() << std::endl;
	animalCat->makeSound();

	// =========================================================
	// HEAP POLYMORPHISM TEST
	// =========================================================
	std::cout << RED
		<< "\n========== HEAP POLYMORPHISM TEST ==========\n\n"
		<< RESET;

	Animal *heapDog = new Dog();
	Animal *heapCat = new Cat();

	std::cout << "Dog through Animal pointer:\n";
	std::cout << "Type: " << heapDog->getType() << std::endl;
	heapDog->makeSound();

	std::cout << "\nCat through Animal pointer:\n";
	std::cout << "Type: " << heapCat->getType() << std::endl;
	heapCat->makeSound();

	std::cout << "\nDeleting Dog through Animal pointer...\n";
	delete heapDog;

	std::cout << "\nDeleting Cat through Animal pointer...\n";
	delete heapCat;

	// =========================================================
	// ANIMAL ARRAY TEST
	// =========================================================
	std::cout << RED
		<< "\n========== ANIMAL ARRAY TEST ==========\n\n"
		<< RESET;

	std::cout << "Creating 5 Dogs and 5 Cats...\n\n";

	Animal *animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();

	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << "Testing every Animal in the array:\n\n";

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Animal [" << i << "] -> "
			<< animals[i]->getType() << ": ";

		animals[i]->makeSound();
	}

	// =========================================================
	// DELETE AS ANIMAL TEST
	// =========================================================
	std::cout << RED
		<< "\n========== DELETE AS ANIMAL TEST ==========\n\n"
		<< RESET;

	std::cout << "Deleting every Animal through Animal pointers...\n\n";

	for (int i = 0; i < 10; i++)
		delete animals[i];

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

	// =========================================================
	// END
	// =========================================================
	std::cout << RED
		<< "\n==================================================\n"
		<< "                    END TESTS\n"
		<< "==================================================\n\n"
		<< RESET;

	return (0);
}