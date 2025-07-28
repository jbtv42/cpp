#ifndef B_HPP
#define B_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private : 
        const std::string   name;
        int                 grade;

    public :

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);

    class GradeTooHighException: public std::exception{
        public :
            const char* what() const throw() { return ("Grade too high");}
    };
    class GradeTooLowException: public std::exception{
        public :
            const char* what() const throw() { return ("Grade too low");}
    };

    int                 getGrade() const;
    const std::string&  getName() const;
    Bureaucrat& operator=(const Bureaucrat& other);

    void    increment();
    void    decrement();
    void    signForm(AForm& F);
    void    executeForm(AForm const & form) const;
};    

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);

#endif