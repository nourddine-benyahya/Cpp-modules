/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:16:09 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/10/22 13:17:45 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}
void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}
void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}
void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl ;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void  Harl::complain( std::string level )
{
    int i = 0;
    std::string cases[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (level != cases[i] && i < 4)
        i++;
    switch (i)
    {
        case 0: this->debug();
        case 1: this->info();
        case 2: this->warning();
        case 3: this->error(); break;
        default:  std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; ; break;
    }
}