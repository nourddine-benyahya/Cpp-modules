#include "Bureaucrat.hpp"
#include "AForm.hpp" 

void actionMessage(const std::string& msg)
{
    #ifdef DEBUG
        std::cout << "Bureaucrat " << msg << " is called" << std::endl;
    #else
        (void)msg;
    #endif
}

Bureaucrat::Bureaucrat(): name("defaultName"), grade(100){
    actionMessage("Constracter");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade){
    actionMessage("parameterized constructor");
    if (grade <= 1)
        throw GradeTooHighException();
    else if (grade >= 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj): name(obj.name), grade(obj.grade){
    actionMessage("copy constructor");
}

Bureaucrat::~Bureaucrat(){
    actionMessage("destructor");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj) {
        grade = obj.grade;
    }
    actionMessage("copy assignment");
    return *this;
}

int Bureaucrat::getGrade() const
{
    actionMessage("getGrade Method");
    return grade;
}

const std::string& Bureaucrat::getName() const
{
    actionMessage("getName Method");
    return name;
}

void Bureaucrat::incrementGrade()
{
    actionMessage("incrementGrade Method");
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    actionMessage("decrementGrade Method");
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    actionMessage("TooHigh Exception");
    return "TOO HIGH";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    actionMessage("TooLow Exception");
    return "TOO LOW";
}

void Bureaucrat::signForm(AForm &form)
{
    actionMessage("signForm Method");
    try
    {
        form.beSigned(*this);
        std::cout << name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    actionMessage("executeForm Method");
    try
    {
        form.execute(*this);
        std::cout << name << " executes " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    actionMessage("overload operator");
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return out;
}