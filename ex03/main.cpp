/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 02:55:29 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/05 02:55:31 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"


int	main(void)
{
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD NOT CREATE PRESIDENTIAL PARDON FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("wesh wesh presidential pardon", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD CREATE PRESIDENTIAL PARDON FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Valid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("presidential pardon", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD NOT CREATE ROBOTOMY REQUEST FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("robotomy papy", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD CREATE ROBOTOMY REQUEST FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Valid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("robotomy request", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD NOT CREATE SHRUBBERY CREATION FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("shrubbery ta vu", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD CREATE SHRUBBERY CREATION FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Valid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("shrubbery creation", "soso");
		if (form)
			delete form;
	}
	std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ END $$$$$$$$$$$$$$$$$$$$$$\n\n";
	return (0);
}
