/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:23:53 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/06 02:23:54 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("unnamed"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw(GradeTooHighException());
	if (_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) : _name(other._name), _grade(other._grade) {}

std::string const &	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat: grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat: grade too low");
}

void	Bureaucrat::incrementGrade(int n) {
	if (n <= 0)
		return ;
	if (_grade - n < 1)
		throw (GradeTooHighException());
	_grade -= n;
}

void	Bureaucrat::decrementGrade(int n) {
	if (n <= 0)
		return ;
	if (_grade + n > 150)
		throw (GradeTooLowException());
	_grade += n;
}

void	Bureaucrat::signForm(AForm& form) const {
	if (form.getIsSigned())
		return ;
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	} catch (std::exception& e) {
		std::cout << _name
				  << " couldn't sign "
				  << form.getName()
				  << " because "
				  << e.what() << ".\n"; 
	}
} 

void	Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n" << _name << " could not execute " << form.getName() << "\n";	
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (out);
}
