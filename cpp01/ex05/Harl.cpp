
#include "Harl.hpp"

Harl::Harl()
{
	levels["DEBUG"] = &Harl::debug;
    levels["INFO"] = &Harl::info;
    levels["WARNING"] = &Harl::warning;
    levels["ERROR"] = &Harl::error;
};

Harl::~Harl()
{

};

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
};

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
};

void Harl::error(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
};

void Harl::complain(std:: string level)
{
	std::map<std::string, HarlMemFn>::iterator lvl = levels.find(level);
	if (lvl != levels.end()) // this means like the null terminator element in an array
		(this->*(lvl->second))();
	else
		std::cout << "level unknown" <<std::endl;
};