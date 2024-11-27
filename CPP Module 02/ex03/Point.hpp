/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:30:02 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/26 17:29:17 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private : 
        Fixed x; //const
        Fixed y;
        float area(const Point &a, const Point &b, const Point &c);
    public :
        Point();
        float getX() const;
        float getY() const;
        Point(const float new_x, const float new_y);
        Point(const Point &new_point);
        Point &operator=(const Point &new_point);
        bool bsp( Point const a, Point const b, Point const c, Point const point);
        ~Point();
};