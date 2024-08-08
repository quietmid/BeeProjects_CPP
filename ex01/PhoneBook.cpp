/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:33:50 by jlu               #+#    #+#             */
/*   Updated: 2024/08/08 23:31:02 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::print_contacts()
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

void	PhoneBook::add_contacts(std::string info[5])
{
	int idx;

	idx = this->idx;
	contacts[idx].set_firstName(info[0]);
	contacts[idx].set_lastName(info[1]);
	contacts[idx].set_nickName(info[2]);
	contacts[idx].set_pNumber(info[3]);
	contacts[idx].set_darkSecret(info[4]);
	if (this->idx < 8)
		this->idx++;
	else
		this->idx = 0;
	if (this->size < 8)
		this->size++;
};