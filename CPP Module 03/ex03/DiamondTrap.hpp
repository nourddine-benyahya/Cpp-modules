/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:17:07 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/12/01 12:29:06 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private :
        std::string Name;

    public :
        DiamondTrap();
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap &obj);
        DiamondTrap &operator=(const DiamondTrap &obj);
        ~DiamondTrap();

        // void attack(const std::string& target);
        void whoAmI(void);
};

#endif