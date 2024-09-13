/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:20:17 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/02 11:11:46 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private :
        Weapon &weapon;
        std::string name;
    public :
        HumanA(std::string new_name, Weapon &new_weapon);
        ~HumanA(void);
        void attack(void);
};

#endif