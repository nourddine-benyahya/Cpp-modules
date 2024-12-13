#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("non")
{
    std::cout << "WrongAnimal constracter called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type)
{
    std::cout << "WrongAnimal parameterized constracter called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : type(obj.type)
{
    std::cout << "WrongAnimal copy constracter called" << std::endl;
}


WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Deconstracter Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    if (this != &obj)
        this->type = obj.type;
    std::cout << "WrongAnimal copy assigment operator called" << std::endl;
    return (*this);
}

std::string WrongAnimal::getType()
{
    return (this->type);
}
void WrongAnimal::makeSound(void) const
{
    std::cout << "This WrongAnimal doesn't make any sound." << std::endl;
}