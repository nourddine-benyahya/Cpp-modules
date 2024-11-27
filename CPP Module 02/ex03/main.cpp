/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:19:28 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/11/26 17:34:49 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0, 3);
    Point b(-2, -2);
    Point c(2, 0);
    Point p(0, 0.001);
    Point test;
    std::cout << (test.bsp(a,b,c,p) ? "inside" : "outside") << std::endl;
}
