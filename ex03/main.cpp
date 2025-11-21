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

#include <exception>
#include <iomanip>
#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"


int	main(void)
{
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ COULD NOT CREATE PRESIDENTIAL PARDON FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("presidential", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ COULD CREATE PRESIDENTIAL PARDON FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Valid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("presidential pardon", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ COULD NOT CREATE ROBOTOMY REQUEST FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("robotomy", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ COULD CREATE ROBOTOMY REQUEST FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Valid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("robotomy request", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ COULD NOT CREATE SHRUBBERY CREATION FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	form;

		form = foo.makeForm("shrubbery", "soso");
		if (form)
			delete form;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ COULD CREATE SHRUBBERY CREATION FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
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
