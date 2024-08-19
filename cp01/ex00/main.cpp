
#include "Zombie.hpp"

Zombie* newZombie(std::string name);

void randomChump(std::string name);

int	main(void)
{
	Zombie *zz = newZombie("Donald");
	zz->announce();
	randomChump("Frank");
	delete zz;
	return (0);
}