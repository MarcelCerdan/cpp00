/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:40:50 by mthibaul          #+#    #+#             */
/*   Updated: 2023/07/30 19:06:47 by mthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {return ;}

Harl::~Harl() {return ;}

void	Harl::complain(std::string level) {

	int			i = 0;
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	void		(Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	while (i < 4)
	{
		if (levels[i].compare(level) == 0)
		{
			(this->*f[i])();
			return ;
		}
		i++;
	}
	std::cout << "This level doesn't exist, try debug, info, warning or error."
			<< std::endl ;
			
}

void	Harl::debug() {

	std::cout << "I love having extra bacon for my 7XL\
-double-cheese-triple-pickle-specialketchup burger. I really do !"
			<< std::endl;
}

void	Harl::info() {

	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
			<< std::endl;
}

void	Harl::warning() {

	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month."
			<< std::endl;

}

void	Harl::error() {

	std::cout << "This is unacceptable ! I want to speak to the manager now."
			<< std::endl;
}