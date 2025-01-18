#include "Span.hpp"

int main()
{ 
    Span vc(5);
    try 
    {
        vc.addNumber(2);
        vc.addNumber(12);
        vc.addNumber(5);
        vc.addNumber(-13);
        vc.addNumber(0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        std::cout << "longest span : " << vc.longestSpan() << std::endl;
        std::cout << "shortest span : " << vc.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Span vc1(10);
    std::vector<int> vctr;
    vc1.addNumber(2);
    vc1.addNumber(12);
    vc1.addNumber(5);
    vc1.addNumber(-13);
    vc1.addNumber(0);
    vctr.push_back(11);
    vctr.push_back(22);
    vctr.push_back(33);
    vctr.push_back(44);
    vctr.push_back(55);


    try
    {
        vc1.rango(vctr.begin(), vctr.end());
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try{
        std::cout << "longest span : " << vc1.longestSpan() << std::endl;
        std::cout << "shortest span : " << vc1.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}