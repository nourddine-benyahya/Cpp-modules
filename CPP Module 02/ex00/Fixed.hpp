/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:58:59 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/27 13:06:39 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"

class Fixed 
{
    private :
        int fixedPoint;
        static const int fractionalBit;
    public :
        Fixed();
        Fixed(Fixed &obj);
        Fixed &operator=(const Fixed &obj);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();
};

#endif