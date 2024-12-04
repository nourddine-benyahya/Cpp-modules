#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(const std::string type);
        Cat(const Cat &type);
        Cat &operator=(const Cat &obj);
        ~Cat();

        void makeSound(void) const;

};