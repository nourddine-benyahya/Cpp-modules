/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:56:16 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/02 16:53:18 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    private : 
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public :
        Harl(void);
        ~Harl(void);
        void complain( std::string level );
};

#endif