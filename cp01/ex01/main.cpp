
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	int num;
	Zombie *horde;
	
	num = 15;
	horde = zombieHorde(num, "chester");
	for (int i = 0; i < num; i++)
	{
		std::cout << i + 1<< " ";
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}