#include "helper.hpp"

Base * generate(void)
{
    switch (random() % 3)
    {
        case 0 : return new A;
        case 1 : return new B;
        default: return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "undefind class" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)(dynamic_cast<A&>(p));
        std::cout << "A" << std::endl;
        return;
    }
    catch(const std::bad_cast &e){};
    try
    {
        (void)(dynamic_cast<B&>(p));
        std::cout << "B" << std::endl;
        return;
    }
    catch(const std::bad_cast &e){};
        try
    {
        (void)(dynamic_cast<C&>(p));
        std::cout << "C" << std::endl;
        return;
    }
    catch(const std::bad_cast &e){};
    std::cout << "undefind class" << std::endl;
}
