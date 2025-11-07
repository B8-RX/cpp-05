/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 03:35:42 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/07 03:35:44 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <string>
#include "Form.hpp"


Form::Form() : _name("unNamed"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
	std::cout << "Form Default constructor called\n";
}

Form::~Form() {
	std::cout << "Form Destructor called\n";
}

Form::Form(const std::string& name, const int gradeSign, const int gradeExec) 
			: _name(name), _isSigned(false),
			  _gradeToSign(gradeSign), _gradeToExec(gradeExec) {
	std::cout << "Form Name+GradeSign+GradeExec constructor called\n";
}

Form::Form(const Form& other) 
		: _name(other._name), _isSigned(other._isSigned),
		  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	std::cout << "Form Copy constructor called\n";
} 

Form&	Form::operator=(const Form& other) {
	std::cout << "Form Copy assignment operator called\n";
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

const std::string&	Form::getName() const {
	return (_name);
}

bool	Form::getIsSigned() const {
	return (_isSigned);
}

int	Form::getGradeToSign() const {
	return (_gradeToSign);
}

int	Form::getGradeToExec() const {
	return (_gradeToExec);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
		try {
			if (bureaucrat.getGrade() > _gradeToSign)
				throw(GradeTooLowException());
			_isSigned = true;
			std::cout << bureaucrat.getName() << " signed " << _name << "\n";
		}
		catch (const std::exception& e) {
			std::cout << bureaucrat.getName() << " couldn't sign "
											  << _name << " because "
											  << e.what() << ".\n"; 
		}
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Invalid grade ! Too Low");
}

std::ostream&	operator<<(std::ostream& out, const Form& src) {
	out << "Form " << src.getName()
		<< ", is signed [" << (src.getIsSigned() ? "true" : "false")
		<< "], grade to sign [" << src.getGradeToSign()
		<< "], grade to execute [" << src.getGradeToExec()
		<< "].\n";
	return (out);
}
