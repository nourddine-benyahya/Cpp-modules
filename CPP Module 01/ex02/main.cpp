/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:23:49 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/01 16:37:01 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str;
    str = "HI THIS IS BRAIN";

    std::string *stringPTR;
    stringPTR = &str;

    std::string &stringREF = str;

    std::cout << "The memory address of the string variable is :" << &str << std::endl;
    std::cout << "The memory address held by stringPTR is :" << stringPTR << std::endl;
    std::cout << "The memory address held by stringPTR is :" << &stringREF << std::endl;

    std::cout << "The value of the string variable is :" << str << std::endl;
    std::cout << "The value pointed to by stringPTR is :" << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is :" << stringREF << std::endl;
}