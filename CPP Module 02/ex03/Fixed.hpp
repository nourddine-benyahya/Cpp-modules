/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:24:53 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/26 09:23:38 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"
# include "cmath"

class Fixed 
{
    private :
        int fixedPoint;
        static const int fractionalBit;
    public :
        Fixed();
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(const Fixed &obj);
        Fixed &operator=(const Fixed &obj);
        ~Fixed();
    
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator>(const Fixed &obj) const;
        bool operator<(const Fixed &obj) const;
        bool operator>=(const Fixed &obj) const;
        bool operator<=(const Fixed &obj) const;
        bool operator==(const Fixed &obj) const;
        bool operator!=(const Fixed &obj) const;
        Fixed operator+(const Fixed &obj) const;
        Fixed operator-(const Fixed &obj) const;
        Fixed operator*(const Fixed &obj) const;
        Fixed operator/(const Fixed &obj) const;
        Fixed& operator++();
        Fixed operator++(int);
        static Fixed &min(Fixed &obj1, Fixed &obj2);
        static Fixed &max(Fixed &obj1, Fixed &obj2);
        static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
        static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
        
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif