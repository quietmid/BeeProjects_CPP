
#pragma once

#include "contact.hpp"
#include <iostream>
#include <string>

class PhoneBook 
{
	private:
		Contact contacts[8];
		int idx; //
		int	size; // track how many contacts are there
	
	public:
		PhoneBook() : idx(0), size(0) {}
		// ~PhoneBook(void);
		void	add_contacts(std::string info[5]);
		void	print_contacts();
};