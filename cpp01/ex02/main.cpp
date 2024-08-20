/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:35:59 by jlu               #+#    #+#             */
/*   Updated: 2024/08/20 15:57:10 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*
Usually memory addresses are represented in hexadecimal. 
In c++ you can get the memory address of a variable by using the & operator, 
like:
cout << &i << endl;
*/

int main (void)
{
    std::string myString = "HI THIS IS BRAIN";
    /*
        stringPTR: a pointer to myString
        stringREF: a reference to myString
    */
   std::cout << myString << std::endl;
   std::cout << &myString << std::endl;
   return 0;
}