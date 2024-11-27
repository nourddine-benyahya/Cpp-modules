/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:02:04 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/26 15:39:30 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0) ,y(0) {};

Point::Point(const float new_x, const float new_y) : x(new_x) , y(new_y) {};

Point::Point(const Point &new_point) : x(new_point.x) , y(new_point.y) {};

Point &Point::operator=(const Point &new_point)
{
    if (this != &new_point)
    {
        this->x = new_point.x;
        this->y = new_point.y;
    }
    return (*this);
}

float Point::area(const Point &a, const Point &b, const Point &c)
{
    float res = 
        0.5 * (
        (a.x.toFloat() * (b.y.toFloat() - c.y.toFloat()))
        + (b.x.toFloat() * (c.y.toFloat() - a.y.toFloat()))
        + (c.x.toFloat() * (a.y.toFloat() - b.y.toFloat()))
        );
    return (res < 0.0 ? res * -1 : res);
};


bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
    float totalArea = area(a, b, c);
    float subArea = area(point, b, c) + area(a, point, c) + area(a, b, point);
    return (subArea - totalArea == 0.00);
};

float Point::getX() const
{
    return (x.toFloat());
}
float Point::getY() const
{
    return (y.toFloat());
}

Point::~Point(){
};
