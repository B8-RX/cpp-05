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

int	main(void)
{
	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test good instance (default values)\n";
	try {
		Bureaucrat *unknow = new Bureaucrat();
		std::cout << *unknow << "\n";	
		delete unknow;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\n";
	std::cout << "Test bad instance (grade = 1200)\n";
	try {
		Bureaucrat bob("bob", 1200);
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << "Test bad instance (grade = 0)\n";
	try {
		Bureaucrat john("john", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\n";
	std::cout << "Test good instance (grade = 55)\n";
	try {
		Bureaucrat soso("soso", 55);
		std::cout << soso << "\n";	
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test overloading operator (<<) output format: [<name>, bureaucrat grade <grade>.]\n";
	Bureaucrat soso("soso", 55);
	std::cout << soso << "\n";	

	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "DECREMENTATION:\n";
	std::cout << "Invalid decrementation test (Too low)\n";
	try {
		Bureaucrat soso("soso", 55);
		soso.decrementGrade(200);
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "Valid decrementation test (from grade 55, new grade should be 60)\n";
	try {
		Bureaucrat soso("soso", 55);
		soso.decrementGrade(5);
		std::cout << soso << "\n";
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\n";
	std::cout << "INCREMENTATION:\n";
	std::cout << "Invalid incrementation test (too high)\n";
	try {
		Bureaucrat soso("soso", 55);
		soso.incrementGrade(200);
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "Valid incrementation test (from grade 55, new grade should be 50)\n";
	try {
		Bureaucrat soso("soso", 55);
		soso.incrementGrade(5);
		std::cout << soso << "\n";
	} catch (std::exception & e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
	return (0);
}
