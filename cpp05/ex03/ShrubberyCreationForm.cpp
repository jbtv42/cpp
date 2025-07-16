#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    (void)other;
    return *this; // Nothing assignable (target is const)
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    executeAction();
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
        throw std::runtime_error("Failed to open output file");

    file <<
        "       _-_
"
        "    /~~   ~~\
"
        " /~~         ~~\
"
        "{               }
"
        " \  _-     -_  /
"
        "   ~  \\ //  ~
"
        "_- -   | | _- _
"
        "  _ -  | |   -_
"
        "       | |
";
}
