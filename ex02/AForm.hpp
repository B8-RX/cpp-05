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
#include <exception>

class	Bureaucrat;
class	AForm {
	public:
		AForm(void);
		virtual ~AForm(void) {}
		AForm(const AForm& other);
		AForm(const std::string& name, const int gradeToSign, const int gradeToExec);

		AForm&						operator=(const AForm& other);
		const std::string&			getName(void) const;
		bool						getIsSigned(void) const;
		int							getGradeToSign(void) const;
		int							getGradeToExec(void) const;
		void						beSigned(const Bureaucrat& b);
		class						GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class						GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class						FormNotSignedException : public std::exception {
			virtual const char* what() const throw();
		};
		std::string					resizeName(const std::string& str, size_t size) const;		
		void						execute(const Bureaucrat& executor) const;					
	protected:
		virtual void				executeForm(void) const = 0;
	private:
		const std::string			_name;
		bool						_isSigned;
		const int					_gradeToSign;
		const int					_gradeToExec;
};

std::ostream&						operator<<(std::ostream& out, const AForm& src);

#endif // FORM_HPP
