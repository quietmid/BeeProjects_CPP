
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	const int animalMax = 4;
	Animal* meta[animalMax];
	std::cout << "\n------Cultivating DNA and creating Cats and Dogs------" << std::endl;
	for (int i = 0; i < animalMax; i++)
	{
		if (i % 2 == 0)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	std::cout << "\n-----teaching tricks------" << std::endl;
	for (int i = 0; i < animalMax; i++)
	{
		if (auto dog = dynamic_cast<Dog*>(meta[i]))
		{
			dog->setIdea(0, "I am a dog");
			dog->setIdea(1, "this grass smells like piss, let me roll on it");
			dog->setIdea(2, "That cat looks mean and dangerous.. let me approach");
			dog->setIdea(3, "this person feeds me, pets me and shelters me.. they must be a god!");
		}
		else if (auto cat = dynamic_cast<Cat*>(meta[i]))
		{
			cat->setIdea(0, "I am a cat");
			cat->setIdea(1, "Don't touch me");
			cat->setIdea(2, "let me catch a live roach for my peasant");
			cat->setIdea(3, "this person feeds me, pets me and shelters me.. I must be a god!");
		}
	}
	meta[0]->makeSound();
	auto cat = dynamic_cast<Cat*>(meta[0]);
	std::cout << "meta[0]'s mind: " << cat->getIdea(1) << std::endl;
	meta[1]->makeSound();
	auto dog = dynamic_cast<Dog*>(meta[1]);
	std::cout << "meta[1]'s mind: " << dog->getIdea(1) << std::endl;

	std::cout << "\n-----deleting first round of experiements ------" << std::endl;
	for (int i = 0; i < animalMax; i++)
	{
		delete meta[i];
	}

	std::cout << "\n-----testing copy------" << std::endl;
	Animal* a = new Dog();
	Dog* dogPtr = dynamic_cast<Dog*>(a);
	dogPtr->setIdea(0, "I am a dog");
	std::cout << dogPtr->getIdea(0) << std::endl;
	Dog* dogCopy = new Dog(*dogPtr);
	std::cout << dogCopy->getIdea(0) << std::endl;
	std::cout << "Setting dogCopy idea to I am a copy of a dog" << std::endl;
	dogCopy->setIdea(0, "I am a copy of a dog");
	std::cout << "dogPtr's mind: " << dogPtr->getIdea(0) << std::endl;
	std::cout << "dogCopy's mind: " <<dogCopy->getIdea(0) << std::endl;

	Cat ogCat;
	ogCat.setIdea(0, "I am a cat");
	ogCat.setIdea(1, "Don't touch me");

	Cat newCat;
	newCat = ogCat;
	newCat.setIdea(0, "I am a copy of a cat");
	newCat.setIdea(1, "pet me please");

	std::cout << "ogCat's mind 0: " << ogCat.getIdea(0) << std::endl;
	std::cout << "ogCat's mind 1: " << ogCat.getIdea(1) << std::endl;
	std::cout << "newCat's mind 0: " << newCat.getIdea(0) << std::endl;
	std::cout << "newCat's mind 1: " << newCat.getIdea(1) << std::endl;

	std::cout << "----------Destructors---------" << std::endl;

	delete a;
	delete dogCopy;

	//2 dog destructors called because of copy constructor
	return 0;
}

/* too avoid slicing
int main() {
    Dog ogDog;
    Animal* animalPtr = &ogDog; // Use a pointer to an Animal that points to a Dog
    Animal& animalRef = ogDog;  // Alternatively, use a reference to Animal

    std::cout << "Using pointer:" << std::endl;
    animalPtr->makeSound(); // Calls Dog's makeSound() due to polymorphism

    std::cout << "Using reference:" << std::endl;
    animalRef.makeSound();   // Calls Dog's makeSound() due to polymorphism

    return 0;
}

Explanation
Polymorphic Behavior: Both animalPtr->makeSound() and animalRef.makeSound() will call the overridden makeSound() function in Dog, not Animal, because makeSound() is virtual.
No Slicing: By using a pointer or reference, you retain the full Dog object, and no slicing occurs.

Summary
To avoid slicing when working with inheritance:

Use pointers or references to the base class (Animal* or Animal&) when you need to reference derived class objects (Dog).
This approach will maintain the derived class’s (Dog) behavior and prevent loss of data or functionality.
This design leverages polymorphism and ensures that makeSound() and other overridden functions in derived classes are called correctly.







*/