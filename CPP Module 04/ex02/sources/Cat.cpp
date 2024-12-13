#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const std::string type) : Animal(type), brain(new Brain())
{
    std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj), brain(new Brain(*obj.brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        delete this->brain;
        this->brain = new Brain(*obj.brain);
        this->type = obj.type;
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "MEOWING" << std::endl;
}
