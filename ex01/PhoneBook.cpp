/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:33:50 by jlu               #+#    #+#             */
/*   Updated: 2024/08/09 14:31:57 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

// debug
void	PhoneBook::print_contacts_debug()
{
	int	idx = 0;

	while (!contacts[idx].get_firstName().empty())
	{
		std::cout << "Contact " << idx + 1 << std::endl;
		std::cout << "Name: " << contacts[idx].get_firstName() << " " << contacts[idx].get_lastName() << std::endl;
		std::cout << "Nickname: " << contacts[idx].get_nickName() << std::endl;
		std::cout << "PhoneNumber: " << contacts[idx].get_pNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[idx].get_darkSecret() << std::endl;
		idx++;
	}
}

void	PhoneBook::print_contacts(int opt, int choice)
{
	std::string str[5];

	if (opt == 0) // prints the list of 4 columns
	{
		for (int i = 0; i < this->idx; i++)
		{
			str[0] = contacts[i].get_firstName();
			if (str[0].length() > 10)
				str[0] = str[0].substr(0, 9) + ".";
			str[1] = contacts[i].get_lastName();
			if (str[1].length() > 10)
				str[1] = str[1].substr(0, 9) + ".";
			str[2] = contacts[i].get_nickName();
			if (str[2].length() > 10)
				str[2] = str[2].substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << i + 1 << " | ";
			std::cout << std::right << std::setw(10) << str[0] << " | ";
			std::cout << std::right << std::setw(10) << str[1] << " | ";
			std::cout << std::right << std::setw(10) << str[2] << std::endl;
		};
	}
	else
	{
		std::cout << "Contact " << choice << std::endl;
		choice -= 1;
		std::cout << "Name: " << contacts[choice].get_firstName() << " " << contacts[choice].get_lastName() << std::endl;
		std::cout << "Nickname: " << contacts[choice].get_nickName() << std::endl;
		std::cout << "PhoneNumber: " << contacts[choice].get_pNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[choice].get_darkSecret() << std::endl;
	}
};
void	PhoneBook::add_contacts(std::string info[5])
{
	int idx;

	idx = this->idx;
	contacts[idx].set_firstName(info[0]);
	contacts[idx].set_lastName(info[1]);
	contacts[idx].set_nickName(info[2]);
	contacts[idx].set_pNumber(info[3]);
	contacts[idx].set_darkSecret(info[4]);
	if (this->idx < 7)
		this->idx++;
	else
		this->idx = 0;
	if (this->size < 8)
		this->size++;
};
