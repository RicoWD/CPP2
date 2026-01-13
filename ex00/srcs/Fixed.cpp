/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:03:01 by ep                #+#    #+#             */
/*   Updated: 2026/01/13 19:17:57 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPointNbValue = 0;
	std::cout	<< "Default constructor called\n";
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout	<< "Copy constructor called\n";
	Fixed::operator=(cpy);
	// this->_fixedPointNbValue = cpy._fixedPointNbValue;
}

Fixed &Fixed::operator=(const Fixed &cpy)
{
	if (this->_fixedPointNbValue != cpy._fixedPointNbValue)
			this->_fixedPointNbValue = cpy._fixedPointNbValue;
	std::cout	<< "Copy assignement operator called\n";
	getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called\n";
}

int 	Fixed::getRawBits() const
{
	std::cout	<< "getRawBits member function called\n";
	return (this->_fixedPointNbValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointNbValue = raw;
}
