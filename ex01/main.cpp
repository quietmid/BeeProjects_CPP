/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:33:45 by jlu               #+#    #+#             */
/*   Updated: 2024/08/07 18:33:01 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
  std::string inputName;

  std::cout << "Enter your information:" << std::endl;
  std::cout << "Name: ";
  std::getline(std::cin, inputName);
  std::cout << inputName << std::endl;
  // PhoneBook::getName(std::cin);

  return 0;  
};