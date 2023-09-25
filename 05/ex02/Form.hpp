/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:40:00 by mthibaul          #+#    #+#             */
/*   Updated: 2023/08/23 16:40:00 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

	std::string	const name;
	bool		isSigned;
	int const	gradeToSign;
	int const	gradeToExecute;

	public:

	Form(void);
	Form(std::string name, int grSign, int grExec);
	Form(const Form &other);
	virtual ~Form(void);

	std::string getName() const;
	int 		getGradeToSign() const;
	int 		getGradeToExec() const;
	bool		getIsSigned() const;
	virtual void	beSigned(Bureaucrat *b);

	Form &operator=(const Form &other);

	class	GradeTooHighException : public std::exception {

	public:

		const char *what() const throw() {
			return ("Error : form's grade is too high !");
		}
	};

	class	GradeTooLowException : public std::exception {

	public:

		const char *what() const throw() {
			return ("Error : form's grade is too low !");
		}
	};
};

std::ostream	&operator<<(std::ostream &os, Form const &form);

#endif