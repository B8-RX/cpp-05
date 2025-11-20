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
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int	main(void)
{
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$ COULD NOT SIGN OR EXEC $$$$$$$$$$$$$$$$$$$$\n\n";
		// toto and bob can't sign or execute Forms

		std::cout << "\n\t$$$$$$$$$$$$$$$$$$$$$$$ SHRUBBERY $$$$$$$$$$$$$$$$$$$$\n\n";
		Bureaucrat toto("toto", 150);
		std::cout << toto << "\n";

		AForm	*planA = new ShrubberyCreationForm("home_b");
		std::cout << *planA << "\n";
		toto.executeForm(*planA);
		toto.signForm(*planA);
		std::cout << *planA << "\n";
		toto.executeForm(*planA);
		delete planA;
		
		std::cout << "\n\t$$$$$$$$$$$$$$$$$$$$$$$ ROBOTOMYREQUESTFORM $$$$$$$$$$$$$$$$$$$$\n\n";
		Bureaucrat bob("bob", 150);
		std::cout << bob << "\n";
		
		AForm	*planX = new RobotomyRequestForm("toto");
		std::cout << *planX << "\n";
		bob.executeForm(*planX);
		bob.signForm(*planX);
		std::cout << *planX << "\n";
		bob.executeForm(*planX);
		delete planX;

	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$ COULD SIGN BUT NOT EXEC $$$$$$$$$$$$$$$$$$$$\n\n";
		// toto and bob can sign and execute Forms

		std::cout << "\n\t$$$$$$$$$$$$$$$$$$$$$$$ SHRUBBERY $$$$$$$$$$$$$$$$$$$$\n\n";
		Bureaucrat toto("toto", 140);
		std::cout << toto << "\n";

		AForm	*planB = new ShrubberyCreationForm("home_a");
		std::cout << *planB << "\n";
		toto.executeForm(*planB);
		toto.signForm(*planB);
		std::cout << *planB << "\n";
		toto.executeForm(*planB);
		delete planB;
		
		std::cout << "\n\t$$$$$$$$$$$$$$$$$$$$$$$ ROBOTOMYREQUESTFORM $$$$$$$$$$$$$$$$$$$$\n\n";
		Bureaucrat bob("bob", 72);
		std::cout << bob << "\n";
		
		AForm	*planY = new RobotomyRequestForm("bob");
		std::cout << *planY << "\n";
		bob.executeForm(*planY);
		bob.signForm(*planY);
		std::cout << *planY << "\n";
		bob.executeForm(*planY);
		delete planY;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$ COULD SIGN AND EXEC $$$$$$$$$$$$$$$$$$$$\n\n";
		// toto and bob can sign and execute Forms

		std::cout << "\n\t$$$$$$$$$$$$$$$$$$$$$$$ SHRUBBERY $$$$$$$$$$$$$$$$$$$$\n\n";
		Bureaucrat toto("toto", 1);
		std::cout << toto << "\n";

		AForm	*planC = new ShrubberyCreationForm("home_c");
		std::cout << *planC << "\n";
		toto.executeForm(*planC);
		toto.signForm(*planC);
		std::cout << *planC << "\n";
		toto.executeForm(*planC);
		delete planC;
		
		std::cout << "\n\t$$$$$$$$$$$$$$$$$$$$$$$ ROBOTOMYREQUESTFORM $$$$$$$$$$$$$$$$$$$$\n\n";
		Bureaucrat bob("bob", 1);
		std::cout << bob << "\n";

		AForm	*planZ = new RobotomyRequestForm("home_c");
		std::cout << *planZ << "\n";
		bob.executeForm(*planZ);
		bob.signForm(*planZ);
		std::cout << *planZ << "\n";
		bob.executeForm(*planZ);
		delete planZ;
	}
	{
		std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$ AFTER ASSIGNMENT COULD EXEC $$$$$$$$$$$$$$$$$$$$$$$$\n\n";
		// zulu take alpha's grade and can execute
		
		Bureaucrat	alpha("alpha", 1);
		Bureaucrat	zulu("zulu", 150);
		AForm		*projetA = new RobotomyRequestForm("alpha");
		AForm		*projetZ = new RobotomyRequestForm("zulu");

		std::cout << alpha << "\n";
		alpha.signForm(*projetA);
		alpha.executeForm(*projetA);
		
		std::cout << "\n" << zulu << "\n";
		zulu.signForm(*projetZ);
		zulu.executeForm(*projetZ);
		
		zulu = alpha;

		std::cout << "\n" << zulu << "\n";
		zulu.signForm(*projetZ);
		std::cout << *projetZ << "\n";
		for (int i = 0; i < 10; i++)
			zulu.executeForm(*projetZ);
		delete projetA;
		delete projetZ;
	}
	std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ END $$$$$$$$$$$$$$$$$$$$$$\n\n";
	return (0);
}
