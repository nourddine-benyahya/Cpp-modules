#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"


        struct Node {
            AMateria *m;
            Node *next;
        };
class Character : public ICharacter
{
    private :

        Node *Node;
    
        std::string name;
        AMateria *inventory[4];
        void addback(AMateria *m);
        void deleteAll();
    public :
        Character();
        Character(std::string const & type);
        Character(const Character &obj);
        Character &operator=(const Character &obj);
        virtual ~Character();

        std::string const & getName() const ;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};