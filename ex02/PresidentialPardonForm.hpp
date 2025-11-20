/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 04:30:26 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/20 04:30:27 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class	PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		PresidentialPardonForm(const std::string& target);
	protected:
		void	executeAction(void) const;
	private:
		std::string	_target;
};

#endif // !PRESIDENTIALPARDONFORM_HPP
