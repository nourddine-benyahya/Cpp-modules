/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:01:02 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/19 15:50:37 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "object Contact created" << std::endl;
}

std::string Contact::get_first_name(void)
{
	return first_name;
}

std::string Contact::get_last_name(void)
{
	return last_name;
}

std::string Contact::get_nickname(void)
{
	return nickname;
}

std::string Contact::get_phone_number(void)
{
	return phone_number;
}

std::string Contact::get_darkest_secret(void)
{
	return darkest_secret;
}

void Contact::set_first_name(std::string new_first_name)
{
	first_name = new_first_name;
}

void Contact::set_last_name(std::string new_last_name)
{
	last_name = new_last_name;
}

void Contact::set_nickname(std::string new_nickname)
{
	nickname = new_nickname;
}

void Contact::set_phone_number(std::string new_phone_number)
{
	phone_number = new_phone_number;
}


void Contact::set_darkest_secret(std::string new_darkest_secret)
{
	darkest_secret = new_darkest_secret;
}

Contact::~Contact(void)
{
	std::cout << "object Contact finish it work" << std::endl;
}