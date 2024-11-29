/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:34:28 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/29 15:47:23 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ScavTrap scav1;
    scav1.attack("target1");
    scav1.guardGate();

    ScavTrap scav2("Scavvy");
    scav2.attack("target2");
    scav2.guardGate();

    ScavTrap scav3(scav2);
    scav3.attack("target3");

    scav1 = scav3;
    scav1.attack("target4");

    return 0;
}