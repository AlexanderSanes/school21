/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:50:41 by ael-khni          #+#    #+#             */
/*   Updated: 2022/08/01 17:10:56y ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
    *this = src;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return (*this);
}

static Form *newRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static Form *newPresident(std::string target)
{
    return (new PresidentialPardonForm(target));
}

static Form *newShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

Form*   Intern::makeForm(std::string name, std::string target)
{
    std::string formNames[] =
    {
        "RobotomyRequestForm",
        "PresidentialPardonForm",
        "ShrubberyCreationForm"
    };
    Form*   (*forms[])(const std::string target) =
    {
        &newRobotomy,
        &newPresident,
        &newShrubbery
    };
    for (int i = 0; i < 3; i++)
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i](target);
        }
    std::cout << "Intern cannot create " << name << " form" << std::endl;
    return nullptr;
}