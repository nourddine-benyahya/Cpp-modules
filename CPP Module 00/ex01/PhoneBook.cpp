/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:54:24 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/28 12:36:54 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->contact_count = 0;
    this->first_contact = 0;
}

PhoneBook::~PhoneBook(void){}

void byebye(void)
{
    std::cout << "bye bye" << std::endl;
    exit(0);
}

void PhoneBook::print_ten(std::string s)
{
    int s_size = s.length();
    for (int i = 0; i < 10 ; i++)
    {
        if (i < s_size - 1 && i == 9)
            std::cout << '.';
        else if (i < s_size)
            std::cout << s[i];
        else
            std::cout << ' ';
    }
}
bool PhoneBook::is_number(std::string s)
{
    int i = 0;
    if (s[i] == '+')
        i++;
    for (i = i; i < s.length() && isdigit(s[i]); i++);
    return i != s.length() ? false : true;
}

void PhoneBook::show_infos(Contact contact)
{
    std::cout << "first name" << contact.get_first_name() << std::endl;
    std::cout << "last name" << contact.get_last_name() << std::endl;;
    std::cout << "nickname" << contact.get_nickname() << std::endl;;
    std::cout << "phone number" << contact.get_phone_number() << std::endl;;
    std::cout << "darkest secret" << contact.get_darkest_secret() << std::endl;;
}

void PhoneBook::search(void)
{
    int index;
    std::string line;

    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|--index---|first name|last name-|nickname--|" << std::endl;
    for (int i = 0; i < this->contact_count ; i++)
    {
        std::cout << " -------------------------------------------" << std::endl;
        std::cout << "|" << i + 1 << "         |";
        print_ten(contact[i].get_first_name());
        std::cout << "|";
        print_ten(contact[i].get_last_name());
        std::cout << "|";
        print_ten(contact[i].get_nickname());
        std::cout << "|";
        std::cout << std::endl;
    }
    std::cout << " -------------------------------------------" << std::endl;
    while (1)
    { 
        while (line.empty() || !is_number(line))
        {
            if (std::cin.eof())
                byebye();
            if (line.empty())
                std::cout << "enter the index or 0 for rollback :" << std::endl;
            else
                std::cout << "invalid index try again :" << std::endl;
            std::getline(std::cin, line);
        }
        index = std::stoi(line);
        line.clear();
        std::cout << index << std::endl;
        if (index == 0)
            break;
        if (index < 1 || index >= this->contact_count + 1)
            std::cout << "invalid index. try again" << std::endl;
        else
        {
            show_infos(this->contact[index - 1]);
            break;
        }
    }
}

void PhoneBook::save_line(Contact &contact)
{
    std::string str;
    int i = 0;
    
    while (i < 5)
    {
        if (i == 0)
            std::cout << "first name :" << std::endl;
        else if (i == 1)
            std::cout << "last name :" << std::endl;
        else if (i == 2)
            std::cout << "nickname :" << std::endl;
        else if (i == 3)
            std::cout << "phone number :" << std::endl;
        else if (i == 4)
            std::cout << "darkest secret :" << std::endl;
        std::getline(std::cin, str);
        if (std::cin.eof())
            byebye();
        if (str.empty())
        {
            std::cout << "invalid input retry enter ";
            continue; 
        }
        if (i == 0)
            contact.set_first_name(str);
        else if (i == 1)
            contact.set_last_name(str);
        else if (i == 2)
            contact.set_nickname(str);
        else if (i == 3)
            contact.set_phone_number(str);
        else if (i == 4)
            contact.set_darkest_secret(str);
        i++;
    }
}

void PhoneBook::add()
{
    int index;

    if (contact_count == 8)
    {
        if (first_contact == 8)
            first_contact = 0;
        else
            index = first_contact;
        first_contact++;
        
    }
    else
    {
        index = contact_count;
        contact_count++;
    }
    this->save_line(this->contact[index]);
}

void PhoneBook::menu(void)
{
    std::string order;

    while (1)
    {
        std::cout << "ur order master (ADD, SEARCH and EXIT.): ";
        std::getline(std::cin, order);
        if (std::cin.eof() || !order.compare("EXIT"))
            byebye();
        if (!order.compare("ADD"))
            add();
        else if (!order.compare("SEARCH"))
        {
            if (this->contact_count != 0)
                this->search();
            else
                std::cout << "no data!!! please set some data" << std::endl;
        }
        else
            std::cout << "huh !!!? are retarded MF, there is only (ADD, SEARCH and EXIT) blind ng" << std::endl;
    }
}