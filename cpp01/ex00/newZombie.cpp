
#include "Zombie.hpp"
#include <string>

/* the new operator returns a pointer to the newly created `Zombie` object on the heap*/
Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
};