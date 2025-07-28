#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
        delete rrf;

    rrf = someRandomIntern.makeForm("unknown form", "Nobody");
    if (rrf)
        delete rrf;

    return 0;
}
