#include "AMateria.hpp"

AMateria::AMateria() : type("Default")
{
    #ifdef DEBUG
    std::cout << "AMateria Default constructor called" << std::endl;
    #endif
}

AMateria::AMateria(std::string const & type) : type(type)
{
    #ifdef DEBUG
    std::cout << "AMateria parametrized constructor called" << std::endl;
    #endif
}
AMateria::AMateria(const AMateria &obj) : type(obj.getType())
{
    #ifdef DEBUG
    std::cout << "AMateria copy constructor called" << std::endl;
    #endif
}

AMateria& AMateria::operator=(const AMateria &obj)
{
    if (this != &obj)
        this->type = obj.getType();
    #ifdef DEBUG
    std::cout << "AMateria copy assigment operator called" << std::endl;
    #endif
    return *this;
}

AMateria::~AMateria()
{
    #ifdef DEBUG
    std::cout << "AMateria destructor called" << std::endl;
    #endif
}

std::string const & AMateria::getType() const   
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "this is the base class; there is no message for " << target.getName() << std::endl;
}
