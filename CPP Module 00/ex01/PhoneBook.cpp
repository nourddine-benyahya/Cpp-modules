/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 07:54:24 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/12 10:05:15 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->contact_count = 0;
    this->first_contact = 0;
}

PhoneBook::~PhoneBook(void){}

void PhoneBook::byebye(void)
{
    std::cout << "bye bye" << std::endl;
    exit(0);
}

bool PhoneBook::_is_empty(std::string s)
{
    int start = 0;
    int len = s.length();

    while (s[start] && s[start] == ' ')
        start++;
    while (len > 0 && s[len - 1] == ' ')
        len--;
    std::string a = s.substr(start, len - start);
    if (a.empty())
        return (false);
    return (true);
}

void PhoneBook::print_ten(std::string s)
{
    if (s.length() <= 10)
        std::cout << std::setw(10) << s;
    else
    {
        std::string a = s.substr(0, 9);
        std::cout << a << ".";
    } 
}
bool PhoneBook::is_number(std::string s)
{
    size_t i = 0;
    size_t j = 0;
    for (i = j; i < s.length() && isdigit(s[i]); i++);
    return i != s.length() ? false : true;
}

void PhoneBook::show_infos(Contact contact)
{
    std::cout << "first name : " << contact.get_first_name() << std::endl;
    std::cout << "last name : " << contact.get_last_name() << std::endl;;
    std::cout << "nickname : " << contact.get_nickname() << std::endl;;
    std::cout << "phone number : " << contact.get_phone_number() << std::endl;;
    std::cout << "darkest secret : " << contact.get_darkest_secret() << std::endl;;
}

void PhoneBook::search(void)
{
    int index = 0;
    std::string line;

    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    for (int i = 0; i < this->contact_count ; i++)
    {
        std::cout << " -------------------------------------------" << std::endl;
        std::cout << "|         "<< i + 1 << "|";
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
        std::cout << "enter the index (between 1 and 8) or 0 for rollback :" << std::endl;
        std::getline(std::cin, line);
        while (line.empty() || line.size() != 1 || !is_number(line))
        {
            if (std::cin.eof())
                this->byebye();
            std::cout << "invalid index try again :" << std::endl;
            std::getline(std::cin, line);
        }
        index =  line[0] - '0';
        line.clear();
        if (index == 0)
            break;
        if (index < 1 || index >= this->contact_count + 1)
            std::cout << "invalid index. try again " << std::endl;
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
    std::string trimed_str;
    int start = 0;
    int len = 0;
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
            this->byebye();;
        if (str.empty() || !this->_is_empty(str))
        {
            std::cout << "invalid input retry enter ";
            continue; 
        }
        start = 0;
        len = str.length();
        while (str[start] && str[start] == ' ')
            start++;
        while (len > 0 && str[len - 1] == ' ')
            len--;
        trimed_str = str.substr(start, len - start);
        if (i == 0)
            contact.set_first_name(trimed_str);
        else if (i == 1)
            contact.set_last_name(trimed_str);
        else if (i == 2)
            contact.set_nickname(trimed_str);
        else if (i == 3)
            {
                if (is_number(trimed_str)  && trimed_str.length() < 12)
                    contact.set_phone_number(trimed_str);
                else
                {
                    std::cout << "invalid Phone number retry enter ";
                    continue;
                }
            }
        else if (i == 4)
            contact.set_darkest_secret(trimed_str);
        i++;
    }
}

void PhoneBook::add()
{
    int index = 0;

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
        if (std::cin.eof() || !order.compare("EXIT") || !order.compare("exit"))
            this->byebye();;
        if (!order.compare("ADD") || !order.compare("add"))
            add();
        else if (!order.compare("SEARCH") || !order.compare("search"))
        {
            if (this->contact_count != 0)
                this->search();
            else
                std::cout << "no data!!! please set some data" << std::endl;
        }
        else
            std::cout << "there is only (ADD, SEARCH and EXIT) command" << std::endl;
    }
}