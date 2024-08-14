
#pragma once

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

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
		~PhoneBook(void);
		bool	check_contacts();
		int 	space_checkers(std::string str);
		void	add_contacts(std::string info[5]);
		void	print_contacts(int opt, int choice);
		void	print_contacts_debug();
};

#endif