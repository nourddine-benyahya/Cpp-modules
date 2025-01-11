#include "Form.hpp"

static void actionMessage(const std::string& msg)
{
    #ifdef DEBUG
        std::cout << "Bureaucrat " << msg << " is called" << std::endl;
    #else
        (void)msg;
    #endif
}

Form::Form(): name("defaultName"), isSigned(false), gradeToSign(100), gradeToExecute(100){
    actionMessage("Constracter");
};

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
    actionMessage("parameterized constructor");
};

Form::Form(const Form& obj): name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute){
    actionMessage("copy constructor");
};

Form::~Form(){
    actionMessage("destructor");
};

Form &Form::operator=(const Form &obj)
{
    if (this != &obj) {
        isSigned = obj.isSigned;
    }
    actionMessage("copy assignment");
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << "Form name: " << obj.getName() << std::endl;
    out << "Form is signed: " << obj.getIsSigned() << std::endl;
    out << "Form grade to sign: " << obj.getGradeToSign() << std::endl;
    out << "Form grade to execute: " << obj.getGradeToExecute() << std::endl;
    return out;
}

const std::string& Form::getName() const
{
    actionMessage("getName Method");
    return name;
}

bool Form::getIsSigned() const
{
    actionMessage("getIsSigned Method");
    return isSigned;
}

int Form::getGradeToSign() const
{
    actionMessage("getGradeToSign Method");
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    actionMessage("getGradeToExecute Method");
    return gradeToExecute;
}

void Form::beSigned(Bureaucrat &signer)
{
    actionMessage("beSigned Method");
    if (signer.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    actionMessage("TooHigh Exception");
    return "TOO HIGH";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    actionMessage("TooLow Exception");
    return "TOO LOW";
}

