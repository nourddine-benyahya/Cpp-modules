#pragma once
#include <iostream>

template <typename T>
void easyfind(T container, int find)
{
   typename T::iterator it;
    for (it = container.begin() ; it != container.end(); it++)
    {
        if (*it == find)
        {
            std::cout << "i found it hehe" << std::endl;
            return ;
        }
    }
    std::cout << "i didn't found is , search in ur mom packet!!" << std::endl;
}