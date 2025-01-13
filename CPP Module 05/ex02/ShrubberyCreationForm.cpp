#include "ShrubberyCreationForm.hpp"

static void actionMessage(const std::string& msg)
{
    #ifdef DEBUG
        std::cout << "ShrubberyCreationForm " << msg << " is called" << std::endl;
    #else
        (void)msg;
    #endif
}

ShurbberyCreationForm::ShurbberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("defaultTarget")
{
    actionMessage("Constracter");
}

ShurbberyCreationForm::ShurbberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    actionMessage("parameterized constructor");
}

ShurbberyCreationForm::ShurbberyCreationForm(const ShurbberyCreationForm& other): AForm(other), target(other.target)
{
    actionMessage("copy constructor");
}

ShurbberyCreationForm& ShurbberyCreationForm::operator=(const ShurbberyCreationForm& other)
{
    actionMessage("copy assignment");
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShurbberyCreationForm::~ShurbberyCreationForm()
{
    actionMessage("destructor");
}

void ShurbberyCreationForm::execute(Bureaucrat const &executor) const
{
    actionMessage("execute Method");
    if (this->getIsSigned() == false && executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
    {
        std::ofstream file;
        file.open((target + "_shrubbery").c_str());
        if (!file.is_open())
            std::cout << "Error: could not open file" << std::endl;
        else
        {
            file << 
            "    ccee88oo\n"
            "  C8O8O8Q8PoOb o8oo\n"
            " dOB69QO8PdUOpugoO9bD\n"
            "CgggbU8OU qOp qOdoUOdcb\n"
            "    6OuU  /p u gcoUodpP\n"
            "      \\\\\\//  /douUP\n"
            "        \\\\\\////\n"
            "         |||/\\\n"
            "         |||\\/\n"
            "         |||||\n"
            "   .....//||||\\....\n";
            
            file.close();
        }
    }
}