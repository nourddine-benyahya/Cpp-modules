#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private :
        std::string name;
        AMateria *inventory[4];
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