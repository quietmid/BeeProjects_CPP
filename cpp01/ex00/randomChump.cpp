
#include "Zombie.hpp"


/* use the Zombie class to create a new variable called minion, give it a name and announce on the stack*/
void	randomChump(std::string name)
{
	Zombie minion = Zombie(name);
	minion.announce();
};