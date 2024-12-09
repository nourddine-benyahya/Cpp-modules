#include "Ice.hpp"


Ice::Ice() : AMateria("ice")
{
    #ifdef DEBUG
    std::cout << "Ice Default constructor called" << std::endl;
    #endif
}

Ice::Ice(std::string const & type) : AMateria(type)
{
    #ifdef DEBUG
    std::cout << "Ice parametrized constructor called" << std::endl;
    #endif
}
Ice::Ice(const Ice &obj) : AMateria(obj)
{
    #ifdef DEBUG
    std::cout << "Ice copy constructor called" << std::endl;
    #endif
}

Ice& Ice::operator=(const Ice &obj)
{
    if (this != &obj)
        this->type = obj.getType();
    #ifdef DEBUG
    std::cout << "Ice copy assigment operator called" << std::endl;
    #endif
    return *this;
}

Ice::~Ice()
{
    #ifdef DEBUG
    std::cout << "Ice destructor called" << std::endl;
    #endif
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


AMateria* Ice::clone() const
{
    return new Ice(*this);
}