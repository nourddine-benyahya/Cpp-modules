/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:20:22 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/12 10:54:33 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private :
        Weapon *weapon;
        std::string name;
    public :
        HumanB(std::string new_name);
        ~HumanB(void);
        void setWeapon(Weapon &new_weapen);
        void attack(void);
};

#endif