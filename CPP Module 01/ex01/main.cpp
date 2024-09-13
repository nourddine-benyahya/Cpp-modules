/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:30:19 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/09/12 10:40:11 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 10;
    std::string name = "SI TAYB";

    Zombie *zombies = zombieHorde(10, "SI TAYB");
    for (int i = 0; i < N; i++)
    {
        std::cout << i << " ";  
        zombies[i].announce();
    }

    delete[] zombies;
}