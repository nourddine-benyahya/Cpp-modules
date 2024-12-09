#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
    private :
        Brain *brain;
    public :
        Dog();
        Dog(const std::string type);
        Dog(const Dog &type);
        Dog &operator=(const Dog &obj);
        ~Dog();

        void makeSound(void) const;
};