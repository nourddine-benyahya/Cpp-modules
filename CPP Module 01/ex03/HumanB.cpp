/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:20:19 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/10/22 12:39:24 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string new_name)
{
    this->name = new_name;
    this->weapon = NULL;
}
HumanB::~HumanB(void) { };

void HumanB::setWeapon(Weapon &new_weapen)
{
    this->weapon = &new_weapen;
}


void HumanB::attack(void)
{
    if(!weapon)
        std::cout << "there is no weapon, use mine" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}