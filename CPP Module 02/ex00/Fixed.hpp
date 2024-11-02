/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:58:59 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/10/27 15:22:04 by nbenyahy         ###   ########.fr       */
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
        Fixed &operator=(Fixed &obj);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();
};

#endif