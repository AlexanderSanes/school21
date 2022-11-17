/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:08:40 by ael-khni          #+#    #+#             */
/*   Updated: 2022/08/01 15:13:38by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : Form(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs)
{
    (void)rhs;
    return *this;
}

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();

    std::ofstream file(_target + "_shrubbery");

    file << "   oxoxoo    ooxoo      \n";
    file << "  ooxoxo oo  oxoxooo    \n";
    file << " oooo xxoxoo ooo ooox   \n";
    file << " oxo o oxoxo  xoxxoxo   \n";
    file << "  oxo xooxoooo o ooo    \n";
    file << "    ooo\\oo\\  /o/o       \n";
    file << "        \\  \\/ /         \n";
    file << "         |   /          \n";
    file << "         | D|           \n";
    file << "         |  |           \n";
    file << "         |  |           \n";
    file << "         |  |           \n";
    file << "  ______/____\\____      \n";
    file.close();
}
