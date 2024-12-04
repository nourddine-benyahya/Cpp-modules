#pragma once

#include "Animal.hpp"

class Dog : public Animal 
{
    public :
        Dog();
        Dog(const std::string type);
        Dog(const Dog &type);
        Dog &operator=(const Dog &obj);
        ~Dog();

        void makeSound(void) const;
};