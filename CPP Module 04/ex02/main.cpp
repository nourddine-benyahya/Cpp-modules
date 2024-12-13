#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    Animal *an = new Dog();
    Animal *an2 = new Cat();
    Brain *br = new Brain();

    std::cout << an->getType() << std::endl;
    an->makeSound();


    std::cout << an2->getType() << std::endl;
    an2->makeSound();

    delete an;
    delete an2;
    delete br;

    //-----------test2----------------

    // const int ARRAY_SIZE = 10;
    // Animal* animals[ARRAY_SIZE];

    // for (int i = 0; i < ARRAY_SIZE / 2; ++i)
    //     animals[i] = new Dog();
    // for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i)
    //     animals[i] = new Cat();

    // for (int i = 0; i < ARRAY_SIZE; ++i)
    //     animals[i]->makeSound();

    // for (int i = 0; i < ARRAY_SIZE; ++i)
    //     delete animals[i];

    return 0;
}