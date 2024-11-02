/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:24:57 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/01 16:59:17 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int Fixed::fractionalBit = 8;

Fixed::Fixed() : fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) : fixedPoint(nbr << fractionalBit)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) : fixedPoint(roundf(nbr * (1 << fractionalBit)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed &obj) 
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPoint = obj.fixedPoint;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->fixedPoint = obj.fixedPoint;
    }
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    this->fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)(fixedPoint) / (1 << fractionalBit);
}


int Fixed::toInt( void ) const
{
    return (fixedPoint >> fractionalBit);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}ƒ
