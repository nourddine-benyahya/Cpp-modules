#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(const std::string type);
        WrongCat(const WrongCat &type);
        WrongCat &operator=(const WrongCat &obj);
        ~WrongCat();

        void makeSound(void) const;

};