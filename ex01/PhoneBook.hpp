/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:33:55 by jlu               #+#    #+#             */
/*   Updated: 2024/08/07 18:18:39 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class PhoneBook
{
    char *name;
    char *PhoneNumber;

    char *getName(char *str);
    char *getNumber(char *str);
};