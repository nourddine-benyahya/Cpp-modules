#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main ()
{
    Bureaucrat obj("nourddine",2);
    // AForm obj2("ahmed", 0, 0);

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