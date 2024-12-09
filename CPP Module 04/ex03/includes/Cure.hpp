#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
    public :
        Cure();
        Cure(std::string const & type);
        Cure(const Cure &obj);
        Cure &operator=(const Cure &obj);
        virtual ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);
};
