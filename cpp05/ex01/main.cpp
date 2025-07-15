#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(int argc, char *argv[])
{
    Bureaucrat B1;
    Bureaucrat B2("Sam", 10);
    Form F1("A322", 9, 9);
    
    // try to signe bu grade to low
    try 
    {F1.beSigned(B2);}
    catch(const Form::GradeTooLowException& e)
    {std::cerr << F1 << e.what() << " could not signe " << std::endl;}

    //up grade
    B2.increment();
    B2.increment();
    std::cout << B2 << std::endl;
    
    // succeed to signe
    try 
    {F1.beSigned(B2);}
    catch(const Form::GradeTooLowException& e)
    {std::cerr << F1 << e.what() << " could not signe " << std::endl;}
    
    // new form can't signe but can execute
    Form F2("B344", 1, 20);
    try 
    {F2.beSigned(B2);}
    catch(const Form::GradeTooLowException& e)
    {std::cerr << F2 << e.what() << " could not signe " << std::endl;}

}