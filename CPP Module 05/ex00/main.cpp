#include "Bureaucrat.hpp"

int main ()
{

    try
    {
        Bureaucrat obj("nourddine",160);
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