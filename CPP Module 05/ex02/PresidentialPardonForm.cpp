#include "PresidentialPardonForm.hpp"

static void actionMessage(const std::string& msg)
{
    #ifdef DEBUG
        std::cout << "PresidentialPardonForm " << msg << " is called" << std::endl;
    #else
        (void)msg;
    #endif
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("defaultTarget")
{
    actionMessage("Constracter");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
    actionMessage("parameterized constructor");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target)
{
    actionMessage("copy constructor");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    actionMessage("copy assignment");
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    actionMessage("destructor");
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    actionMessage("execute Method");
    if (this->getIsSigned() == false && executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
    }
}