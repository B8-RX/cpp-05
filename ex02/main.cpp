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

	// soso can sign but not execute plan A
	Bureaucrat soso("soso", 138);
	std::cout << "Bureaucrat [" << soso.getName() << "] is grade [" << soso.getGrade() << "]\n";
	
	AForm	*planA = new ShrubberyCreationForm("home_a");
	std::cout << *planA << "\n";
	try {
		planA->execute(soso);
		std::cout << "soso executed [" << planA->getName() << "] successfully\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
		std::cout << "soso can't execute [" << planA->getName() << "]\n";
	}
	soso.signForm(*planA);
	std::cout << *planA << "\n";
	try {
		planA->execute(soso);
		std::cout << "soso executed [" << planA->getName() << "] successfully\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
		std::cout << "soso can't execute [" << planA->getName() << "]\n";
	}
	
	// trump can't sign or execute plan B
	
	std::cout << "\n\n";
	Bureaucrat trump("trump", 150);
	std::cout << "Bureaucrat [" << trump.getName() << "] is grade [" << trump.getGrade() << "]\n";
	AForm	*planB = new ShrubberyCreationForm("home_b");
	std::cout << *planB << "\n";
	try {
		planB->execute(trump);
		std::cout << "trump executed [" << planB->getName() << "] successfully\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
		std::cout << "trump can't execute [" << planB->getName() << "]\n";
	}
	trump.signForm(*planB);
	std::cout << *planB << "\n";
	try {
		planB->execute(trump);
		std::cout << "trump executed [" << planB->getName() << "] successfully\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
		std::cout << "trump can't execute [" << planB->getName() << "]\n";
	}
	
	// king can sign and execute plan C
	
	std::cout << "\n\n";
	Bureaucrat king("king", 1);
	std::cout << "Bureaucrat [" << king.getName() << "] is grade [" << king.getGrade() << "]\n";
	AForm	*planC = new ShrubberyCreationForm("home_c");
	std::cout << *planC << "\n";
	try {
		planC->execute(king);
		std::cout << "king executed [" << planC->getName() << "] successfully\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
		std::cout << "king can't execute [" << planC->getName() << "]\n";
	}
	king.signForm(*planC);
	std::cout << *planC << "\n";
	try {
		planC->execute(king);
		std::cout << "king executed [" << planC->getName() << "] successfully\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
		std::cout << "king can't execute [" << planC->getName() << "]\n";
	}

	// test with ShrubberyCreationForm called with parameter 'target'
	Bureaucrat john("john", 1);
	std::cout << "Bureaucrat [" << john.getName() << "] is grade [" << john.getGrade() << "]\n";
	AForm	*planD = new ShrubberyCreationForm("home_d");
	std::cout << *planD << "\n";
	try {
		planD->execute(john);
		std::cout << "john executed [" << planD->getName() << "] successfully\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
		std::cout << "john can't execute [" << planD->getName() << "]\n";
	}
	john.signForm(*planD);
	std::cout << *planD << "\n";
	try {
		planD->execute(john);
		std::cout << "john executed [" << planD->getName() << "] successfully\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
		std::cout << "john can't execute [" << planD->getName() << "]\n";
	}
	
	delete planA;
	delete planB;
	delete planC;
	delete planD;
	return (0);
}
// int	main(void)
// {
// 	std::string sep(100, '~');
// 	
//
// 	std::cout << "\n" << sep << "\n";
// 	std::cout << "\n";	
// 	std::cout << std::setw(50) << "INSTANCE CREATION\n\n";
// 	std::cout << "\t[Test: good instance (no input values, should create bureaucrat with default values)]\n";
// 	try {
// 		Bureaucrat *unknow = new Bureaucrat();
// 		std::cout << *unknow << "\n";	
// 		delete unknow;
// 	} catch (std::exception &e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	
// 	std::cout << "\n";
// 	std::cout << "\t[Test: bad instance (grade = 1200)]\n";
// 	try {
// 		Bureaucrat bob("bob", 1200);
// 	} catch (std::exception &e) {
// 		std::cout << e.what() << "\n";
// 	}
//
// 	std::cout << "\n";
// 	std::cout << "\t[Test: bad instance (grade = 0)]\n";
// 	try {
// 		Bureaucrat john("john", 0);
// 	} catch (std::exception &e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	
// 	std::cout << "\n";
// 	std::cout << "\t[Test: good instance (grade = 55)]\n";
// 	try {
// 		Bureaucrat soso("soso", 55);
// 		std::cout << soso << "\n";	
// 	} catch (std::exception &e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	std::cout << "\n" << sep << "\n";
//
// 	std::cout << "\n\n";	
// 	std::cout << std::setw(50) << "OVERLOADING\n\n";
// 	std::cout << "\t[Test: overloading operator (<<) output format: [<name>, bureaucrat grade <grade>.]\n";
// 	Bureaucrat soso("soso", 55);
// 	std::cout << soso << "\n";	
// 	std::cout << "\n" << sep << "\n";
//
// 	std::cout << "\n\n";	
// 	std::cout << std::setw(50) << "GRADE DECREMENT\n\n";
// 	std::cout << "\t[Test: Invalid decrement (input = grade 55, decrementation = 200)]\n";
// 	try {
// 		Bureaucrat soso("soso", 55);
// 		soso.decrementGrade(200);
// 	} catch (std::exception & e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	std::cout << "\n";
// 	std::cout << "\t[Test: Valid decrement (input = grade 55, decrementation = 5, output = should be 60)]\n";
// 	try {
// 		Bureaucrat soso("soso", 55);
// 		soso.decrementGrade(5);
// 		std::cout << soso << "\n";
// 	} catch (std::exception & e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	
// 	std::cout << "\n\n";
// 	std::cout << std::setw(50) << "GRADE INCREMENT\n\n";
// 	std::cout << "\t[Test: Invalid increment (input = grade 55, incrementation = 200)]\n";
// 	try {
// 		Bureaucrat soso("soso", 55);
// 		soso.incrementGrade(200);
// 	} catch (std::exception & e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	std::cout << "\n";
// 	std::cout << "\t[Test: Valid increment (input = grade 55, incrementation = 5, output = should be 50)]\n";
// 	try {
// 		Bureaucrat soso("soso", 55);
// 		soso.incrementGrade(5);
// 		std::cout << soso << "\n";
// 	} catch (std::exception & e) {
// 		std::cout << e.what() << "\n";
// 	}
//
// 	std::cout << "\n" << sep << "\n";
//
// 	std::cout << "\n\n";	
// 	std::cout << std::setw(50) << "FORM TESTS\n\n";
//
// 	std::cout << "[Test: Create successfully a AForm]\n\n";
// 	try {
// 		AForm		projetX("Moon Invasion", 1, 10);
// 		std::cout << projetX << "\n";
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
//
// 	std::cout << "[Test: Trigger Exceptions On AForm Creation]\n\n";
//
// 	std::cout << "\t<--bureaucrat's grade in out-of-bounds range (< 1) for the field [gradeToSign]-->\n";
// 	try {
// 		AForm		projetX("Moon Invasion", 0, 10);
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
// 		
// 	std::cout << "\t<--bureaucrat's grade in out-of-bounds range (> 150) for the field [gradeToSign]-->\n";
// 	try {
// 		AForm		projetX("Moon Invasion", 151, 10);
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
//
// 	std::cout << "\t<--bureaucrat's grade in out-of-bounds range (< 1) for the field [gradeToExecute]-->\n";
// 	try {
// 		AForm		projetX("Moon Invasion", 10, 0);
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
//
// 	std::cout << "\t<--bureaucrat's grade in out-of-bounds range (> 150) for the field [gradeToExecute]-->\n";
// 	try {
// 		AForm		projetX("Moon Invasion", 10, 151);
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	
// 	std::cout << "\n\t\t-------------------------\n";
//
// 	std::cout << "\n";	
// 	std::cout << "[Test: Bureaucrat Attempt To Sign The AForm]\n\n";
// 	std::cout << "\t<--bureaucrat's grade lower than required grade-->\n";
// 	try {
// 		Bureaucrat soso("toto", 20);
// 		AForm		projetX("Moon Invasion", 1, 10);
// 		std::cout << projetX << "\n";
// 		soso.signAForm(projetX);
// 		std::cout << projetX << "\n";
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	std::cout << "\n";
// 	std::cout << "\t<--bureaucrat's grade higher than required grade-->\n";
// 	try {
// 		Bureaucrat soso("soso", 5);
// 		AForm		projetX("Moon Invasion", 21, 10);
// 		std::cout << projetX << "\n";
// 		soso.signAForm(projetX);
// 		std::cout << projetX << "\n";
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	std::cout << "\n";
// 	std::cout << "\t<--bureaucrat's grade equal to required grade-->\n";
// 	try {
// 		Bureaucrat soso("soso", 21);
// 		AForm		projetX("Moon Invasion", 21, 10);
// 		std::cout << projetX << "\n";
// 		soso.signAForm(projetX);
// 		std::cout << projetX << "\n";
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	std::cout << "\n" << sep << "\n";
//
// 	std::cout << "\n";
// 	std::cout << std::setw(50) << "OVERLOADING\n\n";
// 	std::cout << "\t[Test: overloading << to display all the form's information]\n";
// 	try {
// 		AForm		projetX("Moon Invasion", 21, 10);
// 		std::cout << projetX << "\n";
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << "\n";
// 	}
// 	std::cout << "\n" << sep << "\n";
// 	std::cout << "\n";	
// 	return (0);
// }
