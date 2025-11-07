/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 03:22:55 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/07 03:22:56 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

class	Form {
	public:
		Form(void);
		~Form(void);
		Form(const Form& other);
		Form(const std::string& name, const int _gradeToSign, const int _gradeToExec);

		Form&						operator=(const Form& other);
		const std::string&			getName(void) const;
		bool						getIsSigned(void) const;
		int							getGradeToSign(void) const;
		int							getGradeToExec(void) const;
		void						beSigned(const Bureaucrat&);
		class						GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
	private:
		const std::string			_name;
		bool						_isSigned;
		const int					_gradeToSign;
		const int					_gradeToExec;
};

std::ostream&						operator<<(std::ostream& out, const Form& src);

#endif // FORM_HPP
