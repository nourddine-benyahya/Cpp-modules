/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:17:47 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/12 09:27:24 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	std::string str;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		str = av[i];
		for (int j = 0; str[j] != '\0'; j++)
		{
			str[j] = std::toupper(str[j]);
		}
		std::cout << str;
	}
	std::cout << std::endl;
	return 0;
}
