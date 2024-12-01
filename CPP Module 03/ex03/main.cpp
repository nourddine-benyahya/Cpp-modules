/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:34:28 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/12/01 12:27:00 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("DiamondTrap");

    diamond.attack("target");
    diamond.takeDamage(10);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    return 0;
}