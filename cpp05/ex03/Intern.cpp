#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formTypes[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(std::string) = {
        [](std::string t) { return new ShrubberyCreationForm(t); },
        [](std::string t) { return new RobotomyRequestForm(t); },
        [](std::string t) { return new PresidentialPardonForm(t); }
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Intern couldn't find the form named \"" << formName << "\"" << std::endl;
    return NULL;
}
