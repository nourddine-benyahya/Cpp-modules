#include "Animal.hpp"

Animal::Animal() : type("MOUNTASSIR")
{
    std::cout << "Animal constracter called" << std::endl;
}

Animal::Animal(const std::string type) : type(type)
{
    std::cout << "Animal parameterized constracter called" << std::endl;
}

Animal::Animal(const Animal &obj) : type(obj.type)
{
    std::cout << "Animal copy constracter called" << std::endl;
}


Animal::~Animal()
{
    std::cout << "Animal Deconstracter Called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    if (this != &obj)
        this->type = obj.type;
    std::cout << "Animal copy assigment operator called" << std::endl;
    return (*this);
}

std::string Animal::getType()
{
    return (this->type);
}
// void Animal::makeSound(void) const
// {
//     std::cout << "This animal doesn't make any sound." << std::endl;
// }