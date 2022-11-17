#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{

    try
    {
        Bureaucrat bureaucrat("ash", 80);
        Bureaucrat buer("bss", 1);
        ShrubberyCreationForm form1("Shrubbery");   // 145 37
        RobotomyRequestForm form2("Robotomy");      // 72 45
        PresidentialPardonForm form3("President");  // 25 5

        std::cout << "\n--------------- Form 1 (Shrubbery) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        buer.signForm(form1);
        buer.signForm(form1);

        bureaucrat.executeForm(form1);
        std::cout << "\n--------------- Form 2 (Robotomy) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        buer.signForm(form2);
        buer.executeForm(form2);
        buer.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n--------------- Form 3 (President) ---------------" << std::endl;
        buer.signForm(form3);
        bureaucrat.signForm(form3);
        buer.signForm(form3);
        buer.executeForm(form3);
        bureaucrat.executeForm(form3);

    } catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}