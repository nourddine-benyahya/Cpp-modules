/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:17:12 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/23 23:48:02 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook destroctered" << std::endl;
}

void PhoneBook::set_contact(Contact new_contact)
{
    this->contact.push_back(new_contact);
}

void PhoneBook::get_contact(void)
{
    for (int i = 0; i < this->contact.size(); i++)
    {
        this->contact[i].get_first_name();
    }
}

bool PhoneBook::add(void)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    Contact     new_contact;

    std::cout << "first_name" << std::endl;
    std::cin >> first_name;
    std::cout << "last_name" << std::endl;
    std::cin >> last_name;
    std::cout << "nickname" << std::endl;
    std::cin >> nickname;
    std::cout << "phone_number" << std::endl;
    std::cin >> phone_number;
    std::cout << "darkest_secret" << std::endl;
    std::cin >> darkest_secret;
    new_contact.set_first_name(first_name);
    new_contact.set_last_name(last_name);
    new_contact.set_nickname(nickname);
    new_contact.set_phone_number(phone_number);
    new_contact.set_darkest_secret(darkest_secret);
}