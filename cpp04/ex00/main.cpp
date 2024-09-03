
#include "animals.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	std::string type = "sparrow";
	const Animal* m2 = new Animal(type);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrg = new WrongCat();
	std::cout << "-------------------" << std::endl;
	std::cout << "j is " << j->getType() << " " << std::endl;
	std::cout << "i is "<< i->getType() << " " << std::endl;
	std::cout << "meta is "<< meta->getType() << " " << std::endl;
	std::cout << "m2 is "<< m2->getType() << " " << std::endl;
	std::cout << "wrong is "<< wrong->getType() << " " << std::endl;
	std::cout << "wrg is "<< wrg->getType() << " " << std::endl;
	std::cout << "-------------------" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	m2->makeSound();
	wrong->makeSound();
	wrg->makeSound();
	std::cout << "-------------------" << std::endl;
	delete meta;
	delete m2;
	delete j;
	delete i;
	delete wrong;
	delete wrg;

	return 0;
}