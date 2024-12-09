#pragma once

#include <iostream>

class Brain 
{
    public :
        std::string ideas[100];
    public :
        Brain();
        Brain(const std::string ideas[100]);
        Brain(const Brain &ideas);
        Brain &operator=(const Brain &obj);
        ~Brain();
};