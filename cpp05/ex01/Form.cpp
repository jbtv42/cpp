#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors and Destructor
Form::Form() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string& _name, int signGrade, int execGrade)
    : _name(_name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed),
      _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

Form::~Form() {}

// Getters
const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }

// Member Functions
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}

// Stream Operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form "" << form.getName() << "", signed: "
       << (form.isSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade()
       << ", exec grade: " << form.getExecGrade() << ".";
    return os;
}
