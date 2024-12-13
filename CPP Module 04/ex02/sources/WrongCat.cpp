#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constracter called" << std::endl;
}

WrongCat::WrongCat(const std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat parameterized constracter called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj.type)
{
    std::cout << "WrongCat copy constracter called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
        this->type = obj.type;
    std::cout << "WrongCat copy assigment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Deconstracter Called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "MEOWING" << std::endl;
}