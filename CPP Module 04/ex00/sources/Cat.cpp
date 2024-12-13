#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constracter called" << std::endl;
}

Cat::Cat(const std::string type) : Animal(type)
{
    std::cout << "Cat parameterized constracter called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj.type)
{
    std::cout << "Cat copy constracter called" << std::endl;
}
Cat &Cat::operator=(const Cat &obj)
{
    if (this != &obj)
        this->type = obj.type;
    std::cout << "Cat copy assigment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Deconstracter Called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "MEOWING" << std::endl;
}