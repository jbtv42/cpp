#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Basic managment :
Bureaucrat::Bureaucrat() : name("Lazy"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// Grade change functions :

void Bureaucrat::increment(){
    if (grade <= 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement(){
    if (grade >= 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(AForm& F) {
    try {
        F.beSigned(*this);
        std::cout << getName() << " signed " << F.getName() << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cout << getName() << " could not sign " << F.getName()
                  << " because " << e.what() << std::endl;
    }
}

// Get functions :

int Bureaucrat::getGrade() const{
    return (this->grade);
}

const std::string& Bureaucrat::getName() const{
    return (this->name);
}

// Change operators :

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B){
    os << B.getName() << ", bureaucrat grade " << B.getGrade()  << ".";
    return (os);
}

#include "AForm.hpp"

void Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
