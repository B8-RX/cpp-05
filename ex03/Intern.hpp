/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:21:59 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/21 02:22:00 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class	AForm;
class	Intern {
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);

		AForm*	makeForm(const std::string& name, const std::string& target) const;

	private:
		typedef AForm*	(Intern::*t_creator)(const std::string& target) const;

		AForm*			_createShrubbery(const std::string& target) const;
		AForm*			_createRobotomy(const std::string& target) const;
		AForm*			_createPresidential(const std::string& target) const;
};

#endif // !INTERN_HPP
