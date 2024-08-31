/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:17:33 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/30 19:19:24 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Zombie
{
    private :
        std::string name;
    public :
        Zombie( std::string name);
        ~Zombie( void );
        void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );