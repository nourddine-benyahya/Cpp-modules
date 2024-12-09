#pragma once

#include <iostream>

class Animal 
{
    protected :
        std::string type;
    public :
        Animal();
        Animal(const std::string type);
        Animal(const Animal &type);
        Animal &operator=(const Animal &obj);
        virtual ~Animal();

        virtual void makeSound(void) const;
        std::string getType();
};