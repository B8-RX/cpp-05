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
#include "Bureaucrat.hpp"

Form::Form() : _name("unNamed"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
}

Form::~Form() {
}

Form::Form(const std::string& name, const int gradeSign, const int gradeExec) 
			: _name(name), _isSigned(false),
			  _gradeToSign(gradeSign), _gradeToExec(gradeExec) {
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form& other) 
		: _name(other._name), _isSigned(other._isSigned),
		  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
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
		if (bureaucrat.getGrade() > _gradeToSign)
			throw(GradeTooLowException());
		_isSigned = true;
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

Form&	Form::operator=(const Form& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Form& src) {
	out << "Form [" << src.getName()
		<< "], is signed [" << (src.getIsSigned() ? "true" : "false")
		<< "], grade to sign [" << src.getGradeToSign()
		<< "], grade to execute [" << src.getGradeToExec()
		<< "].";
	return (out);
}
