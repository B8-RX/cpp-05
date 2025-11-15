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

#include <cstddef>
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

std::string	Form::resizeName(const std::string& str, size_t size) const {
	if (str.length() >= size)
	{
		std::string res = str.substr(0, size);
		res[size - 1] = '.';
		return (res);
	}
	else
		return (str);
}

std::ostream&	operator<<(std::ostream& out, const Form& src) {
	std::string sep(61, '_');
	size_t		fieldSize = 15;

	out << sep << "\n"
		<< "|" << std::setw(fieldSize) << std::left << "FORM" 
		<< "|" << std::setw(10) << "IS SIGNED"
		<< "|" << std::setw(fieldSize) << "GRADE TO SIGN"
		<< "|" << std::setw(fieldSize) <<  "GRADE TO EXECUTE" << "|\n"
		<< sep << "\n"
		<< "|" << std::setw(fieldSize) << std::right << src.resizeName(src.getName(), fieldSize)
		<< "|" << std::setw(10) << (src.getIsSigned() ? "true" : "false")
		<< "|" << std::setw(fieldSize) << src.getGradeToSign()
		<< "|" << std::setw(fieldSize + 1) << src.getGradeToExec() << "|\n"
		<< sep << "\n";
	return (out);
}
