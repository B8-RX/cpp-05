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

#include <iomanip>
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
	if (_isSigned)
		return ;
	if (bureaucrat.getGrade() > _gradeToSign)
		throw(GradeTooLowException());
	_isSigned = true;
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Form: grade too low");
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Form: grade too high");
}

Form&	Form::operator=(const Form& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Form& src) {
	std::string sep(80, '_');
		
	out << "\t\t"
		<< sep << "\n"
		<< "\t\t"
		<< "|" << std::setw(20) << std::left << "Form" 
		<< "|" << std::setw(15) << "is signed"
		<< "|" << std::setw(20) << "grade to sign"
		<< "|" << std::setw(20) <<  "grade to execute" << "|\n"
		<< "\t\t"
		<< sep << "\n"
		<< "\t\t"
		<< "|" << std::setw(20) << std::right << src.getName()
		<< "|" << std::setw(15) << (src.getIsSigned() ? "true" : "false")
		<< "|" << std::setw(20) << src.getGradeToSign()
		<< "|" << std::setw(20) << src.getGradeToExec() << "|\n"
		<< "\t\t"
		<< sep << "\n";
	return (out);
}
