
#pragma once

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>



class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		typedef void (Harl::*HarlMemFn)(void); // define a type for the pointer to the member function
		std::map<std::string, HarlMemFn> levels; // using std::map to pair up the lvl and the member function
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif