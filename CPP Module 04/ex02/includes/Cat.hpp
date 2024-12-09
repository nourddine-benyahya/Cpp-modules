#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain *brain;
    public :
        Cat();
        Cat(const std::string type);
        Cat(const Cat &type);
        Cat &operator=(const Cat &obj);
        ~Cat();

        void makeSound(void) const;

};