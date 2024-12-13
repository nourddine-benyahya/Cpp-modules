#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

int main()
{
    //-----------------inhiriting with virtual ------------ 
    Animal *an = new Dog();
    Animal *an2 = new Cat();

    std::cout << an->getType() << std::endl;
    an->makeSound();


    std::cout << an2->getType() << std::endl;
    an2->makeSound();

    delete an;
    delete an2;

    //-----------------inhiriting without virtual ------------ 
    // WrongAnimal *an3 = new WrongCat("L7AJJ");

    // std::cout << an3->getType() << std::endl;
    // an3->makeSound();

    // delete an3;
}