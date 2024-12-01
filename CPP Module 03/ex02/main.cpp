/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:34:28 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/30 10:10:05 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {

    FragTrap frag1;
    frag1.highFivesGuys();

    FragTrap frag2("fragvy");

    frag2.highFivesGuys();

    FragTrap frag3(frag2);
    frag3.highFivesGuys();

    frag1 = frag3;
    frag1.highFivesGuys();

    return 0;
}