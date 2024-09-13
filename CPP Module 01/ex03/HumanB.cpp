/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:20:19 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/12 10:54:50 by nbenyahy         ###   ########.fr       */
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
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}