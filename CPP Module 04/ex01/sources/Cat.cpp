#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->brain = new Brain();
    std::cout << "Cat constracter called" << std::endl;
}

Cat::Cat(const std::string type) : Animal(type)
{
    this->brain = new Brain();
    std::cout << "Cat parameterized constracter called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
    type = obj.type;
    delete obj.brain;
    this->brain = new Brain(*obj.brain);
    std::cout << "Cat copy constracter called" << std::endl;
}
Cat &Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        this->brain = new Brain(*obj.brain);
        this->type = obj.type;
    }
    std::cout << "Cat copy assigment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat Deconstracter Called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "MEOWING" << std::endl;
}