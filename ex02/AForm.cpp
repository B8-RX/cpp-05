/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
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
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("unNamed"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
}

AForm::AForm(const std::string& name, const int gradeSign, const int gradeExec) 
			: _name(name), _isSigned(false),
			  _gradeToSign(gradeSign), _gradeToExec(gradeExec) {
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm& other) 
		: _name(other._name), _isSigned(other._isSigned),
		  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
} 

const std::string&	AForm::getName() const {
	return (_name);
}

bool	AForm::getIsSigned() const {
	return (_isSigned);
}

int	AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int	AForm::getGradeToExec() const {
	return (_gradeToExec);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw(GradeTooLowException());
	_isSigned = true;
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Form: grade too low");
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Form: grade too high");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form: form not signed");
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (!_isSigned)
		throw (FormNotSignedException());
	if (executor.getGrade() > getGradeToExec())
		throw (GradeTooLowException());
	executeAction();
}

std::string	AForm::resizeName(const std::string& str, size_t size) const {
	if (str.length() >= size)
	{
		std::string res = str.substr(0, size);
		res[size - 1] = '.';
		return (res);
	}
	else
		return (str);
}

std::ostream&	operator<<(std::ostream& out, const AForm& src) {
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
