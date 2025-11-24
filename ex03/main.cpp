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
#include "Bureaucrat.hpp"

int	main(void)
{
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD NOT CREATE PRESIDENTIAL PARDON FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	formPresidential;

		formPresidential = foo.makeForm("wesh wesh presidential pardon", "soso");
		if (formPresidential)
			delete formPresidential;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD CREATE PRESIDENTIAL PARDON FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Valid input form name
		
		Intern		foo;
		AForm*		formPresidential;
		Bureaucrat	baz("baz", 1);

		formPresidential = foo.makeForm("presidential pardon", "soso");

		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD EXECUTE PRESIDENTIAL PARDON FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		baz.signForm(*formPresidential);
		baz.executeForm(*formPresidential);
		if (formPresidential)
			delete formPresidential;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD NOT CREATE ROBOTOMY REQUEST FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	formRobotomy;

		formRobotomy = foo.makeForm("robotomy papy", "soso");
		if (formRobotomy)
			delete formRobotomy;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD CREATE ROBOTOMY REQUEST FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Valid input form name
		
		Intern	foo;
		AForm*	formRobotomy;
		Bureaucrat	baz("baz", 1);

		formRobotomy = foo.makeForm("robotomy request", "soso");
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD EXECUTE ROBOTOMY REQUEST FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		baz.signForm(*formRobotomy);
		baz.executeForm(*formRobotomy);
		if (formRobotomy)
			delete formRobotomy;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD NOT CREATE SHRUBBERY CREATION FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Invalid input form name
		
		Intern	foo;
		AForm*	formShrubbery;

		formShrubbery = foo.makeForm("shrubbery ta vu", "soso");
		if (formShrubbery)
			delete formShrubbery;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD CREATE SHRUBBERY CREATION FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		// Valid input form name
		
		Intern	foo;
		AForm*	formShrubbery;
		Bureaucrat	baz("baz", 1);

		formShrubbery = foo.makeForm("shrubbery creation", "soso");
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ SHOULD EXECUTE SHRUBBERY CREATION FORM $$$$$$$$$$$$$$$$$$$$$$\n\n";
		baz.signForm(*formShrubbery);
		baz.executeForm(*formShrubbery);
		if (formShrubbery)
			delete formShrubbery;
	}
	std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ END $$$$$$$$$$$$$$$$$$$$$$\n\n";
	return (0);
}
