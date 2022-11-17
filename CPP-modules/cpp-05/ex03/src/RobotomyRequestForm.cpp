/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:21:58 by ael-khni          #+#    #+#             */
/*   Updated: 2022/11/17 13:42:52 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : Form("Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : Form(src), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm& rhs)
{
    (void)rhs;
    return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else
    {
        static int  i;
        if (i % 2 == 0)
            std::cout << "BZZZZZT! " << _target << " has been robotomized!\n";
        else
            std::cout << _target << " failed!\n";
        i++;
        if (i == 2147483647)
            i = 0;
    }
}