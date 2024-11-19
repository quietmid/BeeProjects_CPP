
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "-------Constructors called------" << std::endl;
	const Animal* meta = new Animal();
	std::string type = "sparrow";
	const Animal* m2 = new Animal(type);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrg = new WrongCat();

	std::cout << "---------Animal Types----------" << std::endl;
	std::cout << "meta is "<< meta->getType() << " " << std::endl;
	std::cout << "m2 is "<< m2->getType() << " " << std::endl;
	std::cout << "j is " << j->getType() << " " << std::endl;
	std::cout << "i is "<< i->getType() << " " << std::endl;
	std::cout << "wrong is "<< wrong->getType() << " " << std::endl;
	std::cout << "wrg is "<< wrg->getType() << " " << std::endl;
	
	std::cout << "---------Making Sounds----------" << std::endl;
	meta->makeSound();
	m2->makeSound();
	j->makeSound();
	i->makeSound();
	wrong->makeSound();
	wrg->makeSound();

	std::cout << "-----testing copy------" << std::endl;
	Dog jk;
	Dog k(jk);
	k.makeSound();
	Cat cat;
	Cat c(cat);
	c.makeSound();

	std::cout << "----------Destructors---------" << std::endl;
	delete meta;
	delete m2;
	delete j;
	delete i;
	delete wrong;
	delete wrg;

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