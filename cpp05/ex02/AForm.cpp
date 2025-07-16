#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string& _name, int signGrade, int execGrade)
    : _name(_name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed),
      _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form "" << form.getName()
       << "", signed: " << (form.isSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade()
       << ", exec grade: " << form.getExecGrade() << ".";
    return os;
}
