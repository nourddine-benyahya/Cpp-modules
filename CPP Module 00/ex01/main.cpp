/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:36:02 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/23 23:12:42 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string order;
    PhoneBook phone_book;
    while (1)
    {
        std::cout << "ur order master (ADD, SEARCH and EXIT.): ";
        std::cin >> order;
        if (std::cin.eof())
            continue;
        if (!order.compare("ADD"))
            phone_book.add();
        else if (!order.compare("EXIT"))
            break;
        else
            std::cout << "huh !!!? are retarded MF, ther is only (ADD, SEARCH and EXIT) blind ng" << std::endl;
    }
    phone_book.get_contact();
}