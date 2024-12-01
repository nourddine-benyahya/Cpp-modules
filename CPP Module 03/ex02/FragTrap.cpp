/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:09:50 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/30 10:07:05 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap parameterized constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    ClapTrap::operator=(obj);
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
    	std::cout << "FragTrap " << this->Name << ": You want a high five?" << std::endl;
}
