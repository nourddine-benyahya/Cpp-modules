#include "Intern.hpp"

static void actionMessage(const std::string& msg)
{
    #ifdef DEBUG
        std::cout << "Intern " << msg << " is called" << std::endl;
    #else
        (void)msg;
    #endif
}

Intern::Intern()
{
    actionMessage("Constracter");
}

Intern::Intern(const Intern& other)
{
    actionMessage("copy constructor");
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    actionMessage("copy assignment");
    (void)other;
    return *this;
}

Intern::~Intern()
{
    actionMessage("destructor");
}

AForm *Intern::makeShrubberyCreationForm(const std::string& target)
{
    actionMessage("makeShrubberyCreationForm Method");
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string& target)
{
    actionMessage("makeRobotomyRequestForm Method");
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string& target)
{
    actionMessage("makePresidentialPardonForm Method");
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    actionMessage("makeForm Method");

    std::string action[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*fun[3])(std::string& target) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; i++)
    {
        if (formName == action[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*fun[i])(target);
        }
    }
    std::cout << "Intern can't create " << formName << std::endl;
    return NULL;
}
