/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:09:47 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/12/01 12:29:47 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : ClapTrap
{
    public :
        FragTrap();
        FragTrap(const std::string name);
        FragTrap(const FragTrap &obj);
        FragTrap &operator=(const FragTrap &obj);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif