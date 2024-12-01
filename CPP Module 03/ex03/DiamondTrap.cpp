/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:18:15 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/12/01 12:23:19 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    Energy_points = 50;
    std::cout << "DiamondTrap default constructor called" << std::endl;
    std::cout << Hit_points << Energy_points << Attack_damage << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    Energy_points = 50;
    Name = name;
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
    ClapTrap::operator=(obj);
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << Name << ", ClapTrap name: " << ClapTrap::Name << std::endl;
}

