#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->brain = new Brain();
    std::cout << "Dog constracter called" << std::endl;
}

Dog::Dog(const std::string type) : Animal(type)
{
    this->brain = new Brain();
    std::cout << "Dog parameterized constracter called" << std::endl;
}


Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        this->brain = new Brain(*obj.brain);
        this->type = obj.type;
    }
    std::cout << "Dog copy assigment operator called" << std::endl;
    return (*this);
}

Dog::Dog(const Dog &obj)
{
    type = obj.type;
    delete obj.brain;
    this->brain = new Brain(*obj.brain);
    std::cout << "Dog copy constracter called" << std::endl;
}


Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog Deconstracter Called" << std::endl;
}
void Dog::makeSound(void) const
{
    std::cout << "BARKING" << std::endl;
}