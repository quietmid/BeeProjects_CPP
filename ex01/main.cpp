/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:33:45 by jlu               #+#    #+#             */
/*   Updated: 2024/08/08 23:31:28 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "contact.hpp"
#include <iostream>
#include <string>

int main()
{
  PhoneBook phonebook;
  std::string input;
  std::string info[5]; // 0 - first name 1 - last name 2 - nick name 3 - phonenumber 4 - dark secret


  while (input != "EXIT")
  {
    std::cout << "Please choose your service: ADD, SEARCH, or EXIT" << std::endl;
    std::getline(std::cin, input);
    if (input == "ADD")
    {
      std::cout << "Please Answer the following Questions HONESTLY" << std::endl;
      std::cout << "First Name: " << std::endl;
      std::getline(std::cin, info[0]);
      std::cout << "Last Name: " << std::endl;
      std::getline(std::cin, info[1]);
      std::cout << "Nick Name: " << std::endl;
      std::getline(std::cin, info[2]);
      std::cout << "Phone Number: " << std::endl;
      std::getline(std::cin, info[3]);
      std::cout << "Dark Secret: " << std::endl;
      std::getline(std::cin, info[4]);
      phonebook.add_contacts(info);
      std::cout << "Blackmail material saved" << std::endl;
      phonebook.print_contacts();
    }
    /*
    if input = ADD
      add starts
    if input = SEARCH
      search starts
    if input = EXIt
      return 0
    */
    if (std::cin.eof())
    {
      std::cout << std::endl;
      return (0);
    }
  }
  return 0;  
};

/*
      std::cout << "Input Completed!" << std::endl;
      std::cout << "Name: " << std::endl;
      std::cout << info[0] << " " << info[1] << std::endl;
      std::cout << "Nick Name: " << std::endl;
      std::cout << info[2] << std::endl;
      std::cout << "Phone Number: " << std::endl;
      std::cout << info[3] << std::endl;
      std::cout << "Dark Secret: " << std::endl;
      std::cout << info[4] << std::endl;
*/