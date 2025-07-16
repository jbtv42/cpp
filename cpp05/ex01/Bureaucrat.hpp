#ifndef B_HPP
#define B_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private : 
        const std::string   _name;
        int                 grade;

    public :

    Bureaucrat();
    Bureaucrat(const std::string& _name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);

    class GradeTooHighException: public std::exception{
        public :
            const char* what() const throw();
    };
    class GradeTooLowException: public std::exception{
        public :
            const char* what() const throw();
    };

    int         getGrade() const;
    const std::string& getName() const;
    Bureaucrat& operator=(const Bureaucrat& other);

    void    increment();
    void    decrement();
    void    signForm(Form& F);
};    

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);

#endif