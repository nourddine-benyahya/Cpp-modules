#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "default idea";
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const std::string ideas[100])
{
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = ideas[i];
    }
    std::cout << "Brain parameterized constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = obj.ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
    if (this != &obj) {
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = obj.ideas[i];
        }
    }
    std::cout << "Brain copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}