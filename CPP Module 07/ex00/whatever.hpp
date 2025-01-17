#pragma once

#include <iostream>

template <typename undefindeType>
void swap(undefindeType &a,undefindeType &b){
    undefindeType t;
    t = a;
    a = b;
    b = t;
}

template <typename undefindeType>
undefindeType min(undefindeType a,undefindeType b){
    return a < b ? a : b;
}

template <typename undefindeType>
undefindeType max(undefindeType a,undefindeType b){
    return a > b ? a : b;
}