#include "Character.hpp"
#include <iostream>

Character::Character() : name("Default")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    Node = NULL;
    #ifdef DEBUG
    std::cout << "Character Default constructor called" << std::endl;
    #endif
}

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    Node = NULL;
    #ifdef DEBUG
    std::cout << "Character parametrized constructor called" << std::endl;
    #endif
}

Character::Character(const Character &obj) : name(obj.getName())
{
    Node = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }

    #ifdef DEBUG
    std::cout << "Character copy constructor called" << std::endl;
    #endif
}

Character &Character::operator=(const Character &obj)
{
    Node = NULL;
    if (this != &obj)
    {
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }

        name = obj.getName();
        for (int i = 0; i < 4; i++)
        {
            if (obj.inventory[i])
                inventory[i] = obj.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }

    #ifdef DEBUG
    std::cout << "Character copy assignment operator called" << std::endl;
    #endif

    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = NULL;
    }
    deleteAll();
    #ifdef DEBUG
    std::cout << "Character destructor called" << std::endl;
    #endif
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "Cannot equip a NULL materia" << std::endl;
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

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        addback(inventory[idx]);
        inventory[idx] = NULL;
    }
    else
        std::cout << "Invalid index: " << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
    else
        std::cout << "Invalid inventory index or empty slot" << std::endl;
}

void Character::addback(AMateria *m)
{
    if (!m)
        return;
    struct Node *newNode = new struct Node;
    newNode->m = m;
    newNode->next = NULL;

    if (!Node)
    {
        Node = newNode;
        return;
    }

    struct Node *tmp = Node;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = newNode;
}



void Character::deleteAll()
{
    struct Node *tmp;
    while (Node)
    {
        tmp = Node;
        Node = Node->next;
        delete tmp->m;
        delete tmp;
    }
    Node = NULL;
}

