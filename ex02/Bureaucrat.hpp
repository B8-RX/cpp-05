/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 02:57:14 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/05 02:57:15 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>

class	AForm;
class	Bureaucrat {
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string& name, int grade);
		
		Bureaucrat&					operator=(const Bureaucrat& other);
	
		const std::string&			getName(void) const;
		int							getGrade(void) const;
		void						incrementGrade(int n);
		void						decrementGrade(int n);
		void						signForm(AForm&) const;
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		std::string const			_name;
		int							_grade;
};

std::ostream&						operator<<(std::ostream& out, const Bureaucrat& src);

#endif // !BUREAUCRAT_HPP
