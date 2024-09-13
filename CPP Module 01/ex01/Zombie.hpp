/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:30:21 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/01 16:17:36 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
    private :
        std::string name;
    public :
        Zombie();
        ~Zombie( void );
        void setName(std::string name);
        void announce( void );
};

Zombie* zombieHorde( int N, std::string name );