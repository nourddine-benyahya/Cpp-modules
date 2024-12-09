#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
        private :
            AMateria *inventory[4];
        public :
            MateriaSource();
            MateriaSource(AMateria *inventory[4]);
            MateriaSource(const MateriaSource &obj);
            MateriaSource &operator=(const MateriaSource &obj);
            virtual ~MateriaSource();

            void learnMateria(AMateria *m);
            AMateria* createMateria(std::string const & type);
};