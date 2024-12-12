#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;

    #ifdef DEBUG
    std::cout << "MateriaSource Default constructor called" << std::endl;
    #endif
}

MateriaSource::MateriaSource(AMateria *inventory[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            this->inventory[i] = inventory[i]->clone(); 
        else
            this->inventory[i] = NULL;
    }

    #ifdef DEBUG
    std::cout << "MateriaSource Parameterized constructor called" << std::endl;
    #endif
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    for (int i = 0; i < 4; i++)
    {
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone(); 
        else
            inventory[i] = NULL;
    }

    #ifdef DEBUG
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    #endif
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }

        for (int i = 0; i < 4; i++)
        {
            if (obj.inventory[i])
                inventory[i] = obj.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }

    #ifdef DEBUG
    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    #endif

    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = NULL;
    }

    #ifdef DEBUG
    std::cout << "MateriaSource Destructor called" << std::endl;
    #endif
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
    {
        std::cout << "Cannot learn a NULL materia" << std::endl;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m; 
            return;
        }
    }

    std::cout << "The inventory is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] && inventory[i]->getType() == type)
        {
            return inventory[i]->clone();
        }
    }
    std::cout << "Type not found" << std::endl;
    return NULL;
}
