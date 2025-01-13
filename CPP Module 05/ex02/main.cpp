#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    ShurbberyCreationForm form;
    RobotomyRequestForm form2;
    PresidentialPardonForm form3;



    Bureaucrat bureaucrat("bureaucrat", 1);
    Bureaucrat bureaucrat2("bureaucrat2", 150);
    Bureaucrat bureaucrat3("bureaucrat3", 150);


    try {

        form.beSigned(bureaucrat);
        form2.beSigned(bureaucrat2);
        form3.beSigned(bureaucrat3);
        bureaucrat.executeForm(form);
        bureaucrat2.executeForm(form2);
        bureaucrat3.executeForm(form3);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}