
#include "Zombie.hpp"

int	main(void)
{
	int num;
	Zombie *horde;
	
	num = 15;
	horde = zombieHorde(num, "chester"); //creates an array of Zombies
	for (int i = 0; i < num; i++)
	{
		std::cout << i + 1<< " ";
		horde[i].announce();
	}
	delete [] horde; // deleting the array of Zombies
	return (0);
}