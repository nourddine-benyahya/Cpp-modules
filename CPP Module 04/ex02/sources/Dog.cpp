#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string type) : Animal(type), brain(new Brain())
{
    std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj), brain(new Brain(*obj.brain))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        delete this->brain; 
        this->brain = new Brain(*obj.brain); 
        this->type = obj.type;
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "BARKING" << std::endl;
}
