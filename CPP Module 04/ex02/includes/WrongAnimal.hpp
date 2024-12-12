#pragma once

#include <iostream>

class WrongAnimal 
{
    protected :
        std::string type;
    public :
        WrongAnimal();
        WrongAnimal(const std::string type);
        WrongAnimal(const WrongAnimal &type);
        WrongAnimal &operator=(const WrongAnimal &obj);
        ~WrongAnimal();

        void makeSound(void) const;
        std::string getType();
};