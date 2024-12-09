#include "Character.hpp"

Character::Character() : name("Default")
{
    #ifdef DEBUG
    std::cout << "Character Default constructor called" << std::endl;
    #endif
}

Character::Character(std::string const & name) : name(name)
{
    #ifdef DEBUG
    std::cout << "Character parametrized constructor called" << std::endl;
    #endif
}
Character::Character(const Character &obj) : name(obj.getName())
{
    #ifdef DEBUG
    std::cout << "Character copy constructor called" << std::endl;
    #endif
}
Character& Character::operator=(const Character &obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete this->inventory[i];
        }
        this->name = obj.name;

        for (int i = 0; i < 4; ++i)
        {
            if (obj.inventory[i])
                this->inventory[i] = obj.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    #ifdef DEBUG
    std::cout << "Character copy assignment operator called" << std::endl;
    #endif
    return *this;
}

Character::~Character()
{
    #ifdef DEBUG
    std::cout << "Character destructor called" << std::endl;
    #endif
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
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

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3 && inventory[idx])
        inventory[idx] = NULL;
    else
        std::cout << "invalid inventory or index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3 && inventory[idx])
        inventory[idx]->use(target);
    else
        std::cout << "invalid inventory or index" << std::endl;
}
