#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(std::string const &formName, std::string const &target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string&) = {
        [](const std::string& t) -> AForm* { return new ShrubberyCreationForm(t); },
        [](const std::string& t) -> AForm* { return new RobotomyRequestForm(t); },
        [](const std::string& t) -> AForm* { return new PresidentialPardonForm(t); }
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cerr << "Intern could not find the form: " << formName << std::endl;
    return NULL;
}
