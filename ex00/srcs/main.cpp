/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:54:45 by ep                #+#    #+#             */
/*   Updated: 2026/01/13 19:14:44 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// MAIN FUNCTION GIVEN BY SUBJECT

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;
	
	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return (0);
}
