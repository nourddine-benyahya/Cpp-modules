/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:20:26 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/02 11:01:50 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string new_type)
{
    this->type = new_type;
}
Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string new_type)
{
    this->type = new_type;            
}