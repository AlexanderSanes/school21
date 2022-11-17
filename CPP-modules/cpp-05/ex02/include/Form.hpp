#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;


public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& src);
    virtual ~Form();

    Form&   operator=(const Form& rhs);

    std::string getName() const;
    bool        getSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void        beSigned(const Bureaucrat& bureaucrat);

    virtual void        execute(const Bureaucrat& executor) const = 0;
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class NotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream&   operator<<(std::ostream& os, const Form& rhs);

#endif