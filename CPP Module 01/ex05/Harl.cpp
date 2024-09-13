/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:56:06 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/13 12:41:05 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){};
Harl::~Harl(void){};

void Harl::undefind( void )
{
    std::cout << "undefind level" << std::endl;
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void  Harl::complain( std::string level )
{
    int i = 0;
    void (Harl::*fun[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::undefind};
    std::string cases[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (level != cases[i] && i < 4)
        i++;
    (this->*fun[i])();
}