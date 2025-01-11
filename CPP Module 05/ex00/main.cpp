#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat obj("nourddine",2);

    try
    {
        std::cout << obj;
        obj.incrementGrade();
        std::cout << obj;
        // obj.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}