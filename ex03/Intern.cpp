/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:29:43 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/21 02:29:44 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>


Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return (*this);
}

AForm*	Intern::_createShrubbery(const std::string& target) const {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_createRobotomy(const std::string& target) const {
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_createPresidential(const std::string& target) const {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const {
	const std::string	formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	const t_creator		creatorList[3] = {
		&Intern::_createShrubbery,
		&Intern::_createRobotomy,
		&Intern::_createPresidential
	};
	
	for(int i = 0; i < 3; i++)
	{
		if (formList[i].compare(name) == 0)
		{
			std::cout << "Intern creates " << name << " form\n";
			return ((this->*creatorList[i])(target));
		}
	}
	std::cerr << "Intern could not create form. Invalid name: " << name << "\n";
	return (NULL);
}
