/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:36:03 by jlu               #+#    #+#             */
/*   Updated: 2024/08/14 13:30:20 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
	private:
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		std::string		phoneNum;
		std::string		darkSecret;
	public:
		// Setters
		void	set_firstName(std::string first);
		void	set_lastName(std::string last);
		void	set_nickName(std::string nick);
		void	set_pNumber(std::string phone);
		void	set_darkSecret(std::string secret);
		// Getters
		std::string get_firstName() const ;
		std::string get_lastName() const ;
		std::string get_nickName() const ;
		std::string get_pNumber() const ;
		std::string get_darkSecret() const ;
};

#endif