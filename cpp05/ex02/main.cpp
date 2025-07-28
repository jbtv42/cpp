#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    //work
    try {
        Bureaucrat bob("Bob", 1);

        ShrubberyCreationForm shrubForm("For the knights");
        RobotomyRequestForm roboForm("TargetBot");
        PresidentialPardonForm pardonForm("Alice");

        bob.signForm(shrubForm);
        bob.signForm(roboForm);
        bob.signForm(pardonForm);

        bob.executeForm(shrubForm);
        bob.executeForm(roboForm);
        bob.executeForm(pardonForm);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    //fail
    try {
        Bureaucrat lowRank("Tim", 150);
        ShrubberyCreationForm shrubForm("Garden");

        lowRank.signForm(shrubForm);
        lowRank.executeForm(shrubForm);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
