#include "Bureaucrat.hpp"

int main(int argc, char *argv[])
{
    Bureaucrat B1;
    Bureaucrat B2("Sam", 10);
    try {Bureaucrat B3("Bob", 160);}
    catch (const Bureaucrat::GradeTooLowException& e)
    {std::cerr << "Exeption caught : " << e.what() << std::endl;}

    std::cout << B1 << std::endl;

    try {B1.increment();}
    catch (const Bureaucrat::GradeTooHighException& e)
    {std::cerr << "Exception caught : " << e.what() << std::endl;}
    
    B1.decrement();
    
    try {B1.decrement();}
    catch (const Bureaucrat::GradeTooLowException& e)
    {std::cerr << "Exeption caught : " << e.what() << std::endl;}

    for (int i = 0; i <= 10; i++)
    {
        try {B2.increment();}
        catch(const Bureaucrat::GradeTooHighException& e)
        {std::cerr << "Exeption caught : " << e.what() << std::endl;}
        std::cout << B2 << std::endl;
    }

}