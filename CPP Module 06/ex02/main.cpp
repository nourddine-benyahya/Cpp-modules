#include "helper.hpp"

int main()
{
    Base *ptr = generate();
    Base *ptr2 = generate();
    Base *ptr3 = generate();

    identify(ptr);
    identify(*ptr2);
    identify(*ptr3);
    identify(ptr3);

    delete ptr;
    delete ptr2;
    delete ptr3;
}