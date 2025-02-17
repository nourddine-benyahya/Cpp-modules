/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:48:57 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/12/01 12:29:01 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    // orthodox
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap &obj);
    ScavTrap& operator=(const ScavTrap &obj);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};

#endif