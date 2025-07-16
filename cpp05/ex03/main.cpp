#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;

    AForm* form1 = intern.makeForm("shrubbery creation", "Home");
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    AForm* form3 = intern.makeForm("presidential pardon", "Alice");
    AForm* form4 = intern.makeForm("invalid form", "Target");

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
