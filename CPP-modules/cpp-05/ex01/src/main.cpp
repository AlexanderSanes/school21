#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat1("aaa",11);
        std::cout << bureaucrat1 << std::endl;
        Bureaucrat bureaucrat2("bbb",9);
        std::cout << bureaucrat2 << std::endl;
        Form form("form 1", 10);
        std::cout << form << std::endl;

        bureaucrat1.signForm(form);
        bureaucrat2.signForm(form);
        bureaucrat2.signForm(form);

    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}