#include "Bureaucrat.hpp"

void actionMessage(const std::string& msg)
{
    #ifdef DEBUG
        std::cout << "Bureaucrat " << msg << " is called" << std::endl;
    #else
        (void)msg; // Avoid unused parameter warning
    #endif
}

Bureaucrat::Bureaucrat(): name("defaultName"), grade(100){
    actionMessage("Constracter");
};

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade){
    actionMessage("parameterized constructor");
};

Bureaucrat::Bureaucrat(const Bureaucrat& obj): name(obj.name), grade(obj.grade){
    actionMessage("copy constructor");
};

Bureaucrat::~Bureaucrat(){
    actionMessage("destructor");
};

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
