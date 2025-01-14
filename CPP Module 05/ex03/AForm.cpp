#include "AForm.hpp"

static void actionMessage(const std::string& msg)
{
    #ifdef DEBUG
        std::cout << "Bureaucrat " << msg << " is called" << std::endl;
    #else
        (void)msg;
    #endif
}

AForm::AForm(): name("defaultName"), isSigned(false), gradeToSign(100), gradeToExecute(100){
    actionMessage("Constracter");
};

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
    actionMessage("parameterized constructor");
};

AForm::AForm(const AForm& obj): name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute){
    actionMessage("copy constructor");
};

AForm::~AForm(){
    actionMessage("destructor");
};

AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj) {
        isSigned = obj.isSigned;
    }
    actionMessage("copy assignment");
    return *this;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << "AForm name: " << obj.getName() << std::endl;
    out << "AForm is signed: " << obj.getIsSigned() << std::endl;
    out << "AForm grade to sign: " << obj.getGradeToSign() << std::endl;
    out << "AForm grade to execute: " << obj.getGradeToExecute() << std::endl;
    return out;
}

const std::string& AForm::getName() const
{
    actionMessage("getName Method");
    return name;
}

bool AForm::getIsSigned() const
{
    actionMessage("getIsSigned Method");
    return isSigned;
}

int AForm::getGradeToSign() const
{
    actionMessage("getGradeToSign Method");
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    actionMessage("getGradeToExecute Method");
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &signer)
{
    actionMessage("beSigned Method");
    if (signer.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    actionMessage("TooHigh Exception");
    return "TOO HIGH";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    actionMessage("TooLow Exception");
    return "TOO LOW";
}

