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
        // obj.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        obj.signForm(obj2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}