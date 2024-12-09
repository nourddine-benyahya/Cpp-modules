#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    #ifdef DEBUG
    std::cout << "Cure Default constructor called" << std::endl;
    #endif
}

Cure::Cure(std::string const & type) : AMateria(type)
{
    #ifdef DEBUG
    std::cout << "Cure parametrized constructor called" << std::endl;
    #endif
}
Cure::Cure(const Cure &obj) : AMateria(obj)
{
    #ifdef DEBUG
    std::cout << "Cure copy constructor called" << std::endl;
    #endif
}

Cure& Cure::operator=(const Cure &obj)
{
    if (this != &obj)
        this->type = obj.getType();
    #ifdef DEBUG
    std::cout << "Cure copy assigment operator called" << std::endl;
    #endif
    return *this;
}

Cure::~Cure()
{
    #ifdef DEBUG
    std::cout << "Cure destructor called" << std::endl;
    #endif
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


AMateria* Cure::clone() const
{
    return new Cure(*this);
}