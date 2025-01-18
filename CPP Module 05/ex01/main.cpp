#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    Bureaucrat obj("nourddine",2);
    Form obj2("ahmed", 0, 0);

    try
    {
        std::cout << obj;
        obj.incrementGrade();
        std::cout << obj;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        obj.signForm(obj2);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
}