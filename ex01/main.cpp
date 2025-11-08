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
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "\n";	
	std::cout << "INSTANCE CREATION\n";
	std::cout << "\t[Test: good instance (no input values, should create bureaucrat with default values)]\n";
	try {
		Bureaucrat *unknow = new Bureaucrat();
		std::cout << *unknow << "\n";	
		delete unknow;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\n";
	std::cout << "\t[Test: bad instance (grade = 1200)]\n";
	try {
		Bureaucrat bob("bob", 1200);
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << "\t[Test: bad instance (grade = 0)]\n";
	try {
		Bureaucrat john("john", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\n";
	std::cout << "\t[Test: good instance (grade = 55)]\n";
	try {
		Bureaucrat soso("soso", 55);
		std::cout << soso << "\n";	
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";

	std::cout << "\n";	
	std::cout << "OVERLOADING\n";
	std::cout << "\t[Test: overloading operator (<<) output format: [<name>, bureaucrat grade <grade>.]\n";
	Bureaucrat soso("soso", 55);
	std::cout << soso << "\n";	
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";

	std::cout << "\n";	
	std::cout << "GRADE DECREMENT\n";
	std::cout << "\t[Test: Invalid decrement (input = grade 55, decrementation = 200)]\n";
	try {
		Bureaucrat soso("soso", 55);
		soso.decrementGrade(200);
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "\t[Test: Valid decrement (input = grade 55, decrementation = 5, output = should be 60)]\n";
	try {
		Bureaucrat soso("soso", 55);
		soso.decrementGrade(5);
		std::cout << soso << "\n";
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\n";
	std::cout << "GRADE INCREMENT\n";
	std::cout << "\t[Test: Invalid increment (input = grade 55, incrementation = 200)]\n";
	try {
		Bureaucrat soso("soso", 55);
		soso.incrementGrade(200);
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "\t[Test: Valid increment (input = grade 55, incrementation = 5, output = should be 50)]\n";
	try {
		Bureaucrat soso("soso", 55);
		soso.incrementGrade(5);
		std::cout << soso << "\n";
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";

	std::cout << "\n";	
	std::cout << "FORM TESTS\n";

	std::cout << "Trigger Exceptions On Form Creation\n";
	std::cout << "\t[Test: with grade [to sign] in out-of-bounds range (< 1)]\n";
	try {
		Form		projetX("Moon Invasion", 0, 10);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\t[Test: with grade [to execute] in out-of-bounds range (< 1)]\n";
	try {
		Form		projetX("Moon Invasion", 10, 0);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\t[Test: with grade [to sign] in out-of-bounds range (> 150)]\n";
	try {
		Form		projetX("Moon Invasion", 151, 10);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\t[Test: with grade [to execute] in out-of-bounds range (> 150)]\n";
	try {
		Form		projetX("Moon Invasion", 10, 151);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";

	std::cout << "\n";	
	std::cout << "Bureaucrat Attempt To Sign The Form\n";
	std::cout << "\t[Test: sign with Grade lower than required grade]\n";
	try {
		Bureaucrat soso("toto", 20);
		Form		projetX("Moon Invasion", 1, 10);
		soso.signForm(projetX);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "\t[Test: sign with Grade higher than required grade]\n";
	try {
		Bureaucrat soso("soso", 5);
		Form		projetX("Moon Invasion", 21, 10);
		soso.signForm(projetX);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "\t[Test: sign with Grade equal to required grade]\n";
	try {
		Bureaucrat soso("soso", 21);
		Form		projetX("Moon Invasion", 21, 10);
		soso.signForm(projetX);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";

	std::cout << "\n";
	std::cout << "OVERLOADING\n";
	std::cout << "\t[Test: overloading << to display all the form's information]\n";
	try {
		Form		projetX("Moon Invasion", 21, 10);
		std::cout << projetX << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "\n";	
	return (0);
}
