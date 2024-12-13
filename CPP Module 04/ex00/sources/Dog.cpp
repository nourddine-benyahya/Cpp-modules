#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constracter called" << std::endl;
}

Dog::Dog(const std::string type) : Animal(type)
{
    std::cout << "Dog parameterized constracter called" << std::endl;
}


Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
        this->type = obj.type;
    std::cout << "Dog copy assigment operator called" << std::endl;
    return (*this);
}

Dog::Dog(const Dog &obj) : Animal(obj.type)
{
    std::cout << "Dog copy constracter called" << std::endl;
}


Dog::~Dog()
{
    std::cout << "Dog Deconstracter Called" << std::endl;
}
void Dog::makeSound(void) const
{
    std::cout << "BARKING" << std::endl;
}