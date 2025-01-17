#pragma once

#include <iostream>

template <typename undefindeType,  typename fun>
void iter(undefindeType *a, int b, fun *fn)
{
    for (int i = 0; i < b ; i++)
    {
        fn(a[i]);
    }
};

template <typename f>
void func(f a)
{
    std::cout << a << std::endl;
}