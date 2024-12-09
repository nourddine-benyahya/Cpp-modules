#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    #ifdef DEBUG
    std::cout << "MateriaSource Default constructor called" << std::endl;
    #endif
    for (int i = 0; i < 4 ; i++)
        inventory[i] = NULL;
}

MateriaSource::MateriaSource(AMateria *inventory[4])
{
    for (int i = 0; i < 4 ; i++)
    {
        if (inventory[i])
            this->inventory[i] = inventory[i];
        else
            this->inventory[i] = NULL;
    }
    #ifdef DEBUG
    std::cout << "MateriaSource parametrized constructor called" << std::endl;
    #endif
}
MateriaSource::MateriaSource(const MateriaSource &obj)
{
    for (int i = 0; i < 4 ; i++)
    {
        if (obj.inventory[i])
            inventory[i] =  obj.inventory[i];
        else
            inventory[i] = NULL;
    }
    #ifdef DEBUG
    std::cout << "MateriaSource copy constructor called" << std::endl;
    #endif
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 4 ; i++)
        {
            if (inventory[i])
                delete inventory[i];
            if (obj.inventory[i])
                inventory[i] = obj.inventory[i];
            else
                inventory[i] = NULL;
        }
    }
    #ifdef DEBUG
    std::cout << "MateriaSource copy assigment operator called" << std::endl;
    #endif
    return *this;
}

MateriaSource::~MateriaSource()
{
    #ifdef DEBUG
    std::cout << "MateriaSource destructor called" << std::endl;
    #endif
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return ;
        }
    }
    std::cout << "the inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] && inventory[i]->getType() == type)
            return (inventory[i]->clone());
    }
    std::cout << "type not found" << std::endl;
    return (NULL);
}
