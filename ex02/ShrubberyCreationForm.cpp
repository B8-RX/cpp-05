/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:16:58 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/15 14:16:59 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("unNamed") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	std::cout << "ShrubberyCreationForm Copy constructor called\n";
	_target = other._target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "ShrubberyCreationForm Copy assignment operator called\n";
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm Name constructor called\n";
}

void	ShrubberyCreationForm::executeForm(void) const {
	std::string trees = 
		"         .                    .                        .                    .\n"
		"          .         ;          .         ;              .         ;          .         ;\n"
		"            .        ;%     ;;   .        ;%     ;;       .        ;%     ;;   .        ;%     ;;\n"
		"       ,      ,       :;%  %;      ,       :;%  %;          ,       :;%  %;      ,       :;%  %;\n"
		"        :    ;         :;%;'     ., :    ;         :;%;'     ., :    ;         :;%;'     ., :    ;         :;%;'\n"
		"   %;     %;      ;     %;'    ,; %;     %;      ;     %;'    ,; %;     %;      ;     %;'    ,; %;     %;      ;     %;'\n"
		"   ;%;  %%;   ,   %;  ;%;    ,%'  ;%;  %%;   ,   %;  ;%;    ,%'  ;%;  %%;   ,   %;  ;%;    ,%'  ;%;  %%;   ,   %;  ;%;    ,%'\n"
		"    %;%;   , ;     %;  ;%;   ,%;'  %;%;   , ;     %;  ;%;   ,%;'  %;%;   , ;     %;  ;%;   ,%;'  %;%;   , ;     %;  ;%;   ,%;'\n"
		"     %;     ;%;     % ;%;  ,%;'     %;     ;%;     % ;%;  ,%;'     %;     ;%;     % ;%;  ,%;'     %;     ;%;     % ;%;  ,%;'\n"
		"   `%;.  ;%;  %;'    `;%%;.%;'    `%;.  ;%;  %;'    `;%%;.%;'    `%;.  ;%;  %;'    `;%%;.%;'    `%;.  ;%;  %;'    `;%%;.%;'\n"
		"    `:;%. ;%%. %@;   %; ;@%;%'      `:;%. ;%%. %@;   %; ;@%;%'      `:;%. ;%%. %@;   %; ;@%;%'      `:;%. ;%%. %@;   %; ;@%;%'\n"
		"      `:%;. :;bd%;    %;@%;'          `:%;. :;bd%;    %;@%;'          `:%;. :;bd%;    %;@%;'          `:%;. :;bd%;    %;@%;'\n"
		"        `@%:. :;%.   ;@@%;'             `@%:. :;%.   ;@@%;'             `@%:. :;%.   ;@@%;'             `@%:. :;%.   ;@@%;'\n"
		"          `@%. `;@%. ;@@%;                `@%. `;@%. ;@@%;                `@%. `;@%. ;@@%;                `@%. `;@%. ;@@%;\n"
		"            `@%%.`@%%;@@%;                  `@%%.`@%%;@@%;                  `@%%.`@%%;@@%;                  `@%%.`@%%;@@%;\n"
		"              ;@%.:@%%%@@%;                   ;@%.:@%%%@@%;                   ;@%.:@%%%@@%;                   ;@%.:@%%%@@%;\n"
		"               %@bd%%%bd%%:;                   %@bd%%%bd%%:;                   %@bd%%%bd%%:;                   %@bd%%%bd%%:;\n"
		"                 #@%%%%%:;;                      #@%%%%%:;;                      #@%%%%%:;;                      #@%%%%%:;;\n"
		"                 %@@%%%::;                       %@@%%%::;                       %@@%%%::;                       %@@%%%::;\n"
		"                 %@@@%(o);                       %@@@%(o);                       %@@@%(o);                       %@@@%(o);\n"
		"                 %@@@o%;:(.,                     %@@@o%;:(.,                     %@@@o%;:(.,                     %@@@o%;:(.,\n"
		"             `.. %@@@o%::;                   `.. %@@@o%::;                   `.. %@@@o%::;                   `.. %@@@o%::;\n"
		"                `)@@@o%::;                      `)@@@o%::;                      `)@@@o%::;                      `)@@@o%::;\n"
		"                 %@@(o)::;                       %@@(o)::;                       %@@(o)::;                       %@@(o)::;\n"
		"                .%@@@@%::;                      .%@@@@%::;                      .%@@@@%::;                      .%@@@@%::;\n"
		"                ;%@@@@%::;.                     ;%@@@@%::;.                     ;%@@@@%::;.                     ;%@@@@%::;.\n"
		"               ;%@@@@%%:;;;.                   ;%@@@@%%:;;;.                   ;%@@@@%%:;;;.                   ;%@@@@%%:;;;.\n"
		"           ...;%@@@@@%%:;;;;,..            ...;%@@@@@%%:;;;;,..            ...;%@@@@@%%:;;;;,..            ...;%@@@@@%%:;;;;,..\n";
	std::string		fileName = _target + "_shrubbery"; 
	std::ofstream	outfile(fileName.c_str());
	if (!outfile.is_open()){
		std::cerr << "Error: could not open file [" << fileName << "]\n";
		return ;
	}
	outfile << trees << "\n";
	outfile.close();
}
