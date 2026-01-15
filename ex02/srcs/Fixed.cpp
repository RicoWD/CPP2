/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:58:11 by erpascua          #+#    #+#             */
/*   Updated: 2026/01/15 18:43:36 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

Fixed::Fixed() : _fixedPointNbValue(0)
{
	std::cout	<< "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout	<< "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout	<< "Copy assignment operator called\n";
	if (this != &other)
		_fixedPointNbValue = other._fixedPointNbValue;
	return *this;
}

Fixed::Fixed(const int intToConvert)
{
	std::cout	<< "Int constructor called\n";
	_fixedPointNbValue = intToConvert << Fixed::_nbFractionalBits;
}

Fixed::Fixed(const float floatToConvert)
{
	std::cout	<< "Float constructor called\n";
	_fixedPointNbValue = static_cast<int>(roundf(floatToConvert * (1 << _nbFractionalBits)));
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called\n";
}

/* ************************************************************************** */
// 																			  //
// 									GET/SETERS								  //
//																	 		  //
/* ************************************************************************** */


int 	Fixed::getRawBits() const
{
	std::cout	<< "getRawBits member function called\n";
	return (this->_fixedPointNbValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointNbValue = raw;
}


/* ************************************************************************** */
// 																			  //
// 								MEMBER FUNCTION								  //
//																	 		  //
/* ************************************************************************** */

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointNbValue) / (1 << Fixed::_nbFractionalBits));
}

int		Fixed::toInt(void) const
{
	return _fixedPointNbValue >> _nbFractionalBits;
}

/* ************************************************************************** */
// 																			  //
// 							  EXTERNAL FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

/* ************************************************************************** */
// 																			  //
// 							  COMPARISON OPERATORS							  //
//																	 		  //
/* ************************************************************************** */

bool Fixed::operator>(const Fixed& rhs) const
{

}

bool Fixed::operator<(const Fixed& rhs) const
{
	
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	
}

bool Fixed::operator==(const Fixed& rhs) const
{
	
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	
}

/* ************************************************************************** */
// 																			  //
// 							  ATITHMETIC OPERATORS							  //
//																	 		  //
/* ************************************************************************** */

Fixed Fixed::operator+(const Fixed& rhs) const
{

}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	
}

/* ************************************************************************** */
// 																			  //
// 						 INCREMENT/DECREMENT OPERATORS						  //
//																	 		  //
/* ************************************************************************** */

Fixed& Fixed::operator++()
{
	_fixedPointNbValue++;
	return (*this);
}

Fixed operator++(int n);
{

}

Fixed& operator--();
{
	_fixedPointNbValue--;
	return (*this);
}

Fixed operator--(int n);
{

}
