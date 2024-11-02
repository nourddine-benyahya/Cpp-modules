/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:16:07 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/10/22 13:17:51 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>

class Harl
{
    public :
        void complain( std::string level );
    private : 
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif