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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int	main(void)
{

	std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$ COULD SIGN BUT NOT EXEC $$$$$$$$$$$$$$$$$$$$\n\n";
	// alpha can sign but not execute plan A

	Bureaucrat alpha("alpha", 138);
	std::cout << alpha << "\n";

	AForm	*planA = new ShrubberyCreationForm("home_a");
	std::cout << *planA << "\n";
	alpha.executeForm(*planA);
	alpha.signForm(*planA);
	std::cout << *planA << "\n";
	alpha.executeForm(*planA);

	std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$ COULD NOT SIGN OR EXEC $$$$$$$$$$$$$$$$$$$$\n\n";
	// beta can't sign or execute plan B

	Bureaucrat beta("beta", 150);
	std::cout << beta << "\n";

	AForm	*planB = new ShrubberyCreationForm("home_b");
	std::cout << *planB << "\n";
	beta.executeForm(*planB);
	beta.signForm(*planB);
	std::cout << *planB << "\n";
	beta.executeForm(*planB);

	std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$ COULD SIGN AND EXEC $$$$$$$$$$$$$$$$$$$$\n\n";
	// charlie can sign and execute plan C

	Bureaucrat charlie("charlie", 1);
	std::cout << charlie << "\n";

	AForm	*planC = new ShrubberyCreationForm("home_c");
	std::cout << *planC << "\n";
	charlie.executeForm(*planC);
	charlie.signForm(*planC);
	std::cout << *planC << "\n";
	charlie.executeForm(*planC);

	std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$ AFTER ASSIGNMENT COULD EXEC $$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	// alpha take charlie's values and now can execute
	
	std::cout << alpha << "\n";
	alpha.executeForm(*planA);
	std::cout << "\n";
	
	alpha = charlie;

	std::cout << alpha << "\n";
	std::cout << *planA << "\n";
	alpha.executeForm(*planA);

	std::cout << "\n\n\t$$$$$$$$$$$$$$$$$$$$$$$$$ END $$$$$$$$$$$$$$$$$$$$$$\n\n";
	delete planA;
	delete planB;
	delete planC;
	return (0);
}
