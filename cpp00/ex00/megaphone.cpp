/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:33:37 by jlu               #+#    #+#             */
/*   Updated: 2024/08/07 17:33:39 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
	int i = 1;
	int j;

	if (argc < 2)
		std::cout << "HEY YOU! Ain't no body got time for that!";
	while (argv[i])
	{
		j = 0;
		while (argv[i][j]){
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
};
