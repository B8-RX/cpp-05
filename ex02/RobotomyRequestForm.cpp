/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:35:53 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/20 01:35:55 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("unNamed") {
	std::cout << "RobotomyRequestForm Default constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
	std::cout << "RobotomyRequestForm Copy constructor called\n";
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "RobotomyRequestForm Copy assignment operator called\n";
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm Target constructor called\n";
}

void	RobotomyRequestForm::executeSuccess(void) const {
	std::cout << "brrrrrrrrrrr brrrrrrrrrrrr brrrrrrrrrrrrrr -------- " << _target << " has been robotomized successfully 50\% of the time.\n";
}

void	RobotomyRequestForm::executeFail(void) const {
	std::cout << "Robotomy Failed\n";
}
