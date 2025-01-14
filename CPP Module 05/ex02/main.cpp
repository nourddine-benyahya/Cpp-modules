#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat bureaucrat =  Bureaucrat("0", 6);
    ShurbberyCreationForm shrubberyForm =  ShurbberyCreationForm("1");
    RobotomyRequestForm robotomyForm =  RobotomyRequestForm("2");
    PresidentialPardonForm presidentialForm =  PresidentialPardonForm("3");

    std::cout << bureaucrat;
    std::cout << shrubberyForm;
    std::cout << robotomyForm;
    std::cout << presidentialForm;

    bureaucrat.signForm(shrubberyForm);
    bureaucrat.executeForm(shrubberyForm);

    bureaucrat.signForm(robotomyForm);
    bureaucrat.executeForm(robotomyForm);

    bureaucrat.signForm(presidentialForm);
    bureaucrat.executeForm(presidentialForm);

    std::cout << shrubberyForm;
    std::cout << robotomyForm;
    std::cout << presidentialForm; 


    return 0;
}