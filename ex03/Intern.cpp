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

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const {
	const std::string	formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*				form = NULL;
	int					i = -1;
	
	while (++i < 3)
		if (formList[i].compare(name) == 0)
			break;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
		break;
		case 1:
			form = new RobotomyRequestForm(target);
		break;
		case 2:
			form = new PresidentialPardonForm(target);
		break;
		default:
			std::cerr << "Intern could not make form. Invalid name: " << name << "\n" ;
			return (NULL); 
	}
	std::cout << "Intern creates " << name << " form\n";
	return (form);
}
