#include "RobotomyRequestForm.hpp"

static void actionMessage(const std::string& msg)
{
    #ifdef DEBUG
        std::cout << "RobotomyRequestForm " << msg << " is called" << std::endl;
    #else
        (void)msg;
    #endif
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("defaultTarget")
{
    actionMessage("Constracter");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
    actionMessage("parameterized constructor");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target)
{
    actionMessage("copy constructor");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    actionMessage("copy assignment");
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    actionMessage("destructor");
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    actionMessage("execute Method");
    if (this->getIsSigned() == false && executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "*drilling noises*" << std::endl;
        if (rand() % 2)
            std::cout << target << " has been robotomized successfully" << std::endl;
        else
            std::cout << target << " has been failed to robotomized" << std::endl;
    }
}