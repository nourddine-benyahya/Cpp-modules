#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    Animal *an = new Dog("JACK");
    Animal *an2 = new Cat("L7AJJ");
    Brain *br = new Brain();

    std::cout << an->getType() << std::endl;
    an->makeSound();


    std::cout << an2->getType() << std::endl;
    an2->makeSound();

    delete an;
    delete an2;
    delete br;
}