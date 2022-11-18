#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    _signed = 0;
    if ( gradeToSign < 1 || gradeToExecute < 1 )
        throw Form::GradeTooHighException();
    if ( gradeToSign > 150 || gradeToExecute > 150 )
        throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
}

Form::~Form()
{
}

Form&   Form::operator=( const Form& rhs )
{
    if (this != &rhs)
        this->_signed = rhs.getSigned();
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

bool   Form::getSigned() const
{
    return this-> _signed;
}

int   Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int   Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    else if (this->_signed == false)
	{
		this->_signed = true;
        std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

std::ostream&   operator<<(std::ostream& os, const Form& rhs)
{
    os << "Form name: " << rhs.getName() << "\nGrade to sign: " << rhs.getGradeToSign() << "\nGrade to execute: " << rhs.getGradeToExecute();
    return os;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
};
const char *Form::NotSignedException::what() const throw()
{
  return ("Form not signed");
}