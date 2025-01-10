#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat obj("nourddine",1);

    try
    {
        obj.incrementGrade();
        obj.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}