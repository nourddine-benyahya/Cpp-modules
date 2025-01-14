#include "Intern.hpp"

int main ()
{
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf->execute(Bureaucrat("Bender",15));
    return 0;
}