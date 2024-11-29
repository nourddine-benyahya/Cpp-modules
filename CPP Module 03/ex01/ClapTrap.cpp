/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:24:18 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/29 13:43:42 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
// orthodox
ClapTrap::ClapTrap() : Name("L3ARBI"), Hit_points(10), Energy_points(10), Attack_damage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& new_name) : Name(new_name), Hit_points(10), Energy_points(10), Attack_damage(0) {
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : Name(obj.Name), Hit_points(obj.Hit_points), Energy_points(obj.Energy_points), Attack_damage(obj.Attack_damage) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
    if (this != &obj) {
        this->Name = obj.Name;
        this->Hit_points = obj.Hit_points;
        this->Energy_points = obj.Energy_points;
        this->Attack_damage = obj.Attack_damage;
    }
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " can't attack because it has no hit points or energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    amount < (unsigned int)Hit_points ? Hit_points -= amount : Hit_points = 0;
    std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage! Remaining hit points: " << Hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (Energy_points > 0 && Hit_points > 0)
    {
        Hit_points += amount;
        Energy_points--;
        std::cout << "ClapTrap " << Name << " is repaired by " << amount << " points! Remaining hit points: " << Hit_points << ", remaining energy points: " << Energy_points << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " can't repair because it has no energy points left!" << std::endl;
}