/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:58:11 by erpascua          #+#    #+#             */
/*   Updated: 2026/01/21 15:04:03 by erpascua         ###   ########.fr       */
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
	// std::cout	<< "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout	<< "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout	<< "Copy assignment operator called\n";
	if (this != &other)
		_fixedPointNbValue = other._fixedPointNbValue;
	return *this;
}

Fixed::Fixed(const int intToConvert)
{
	// std::cout	<< "Int constructor called\n";
	_fixedPointNbValue = intToConvert << Fixed::_nbFractionalBits;
}

Fixed::Fixed(const float floatToConvert)
{
	// std::cout	<< "Float constructor called\n";
	_fixedPointNbValue = static_cast<int>(roundf(floatToConvert * (1 << _nbFractionalBits)));
}

Fixed::~Fixed()
{
	// std::cout	<< "Destructor called\n";
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
	return ((this->_fixedPointNbValue) / static_cast<float>(1 << Fixed::_nbFractionalBits));
}

int		Fixed::toInt(void) const
{
	return _fixedPointNbValue >> _nbFractionalBits;
}

/* ************************************************************************** */
// 																			  //
// 							  COMPARISON OPERATORS							  //
//																	 		  //
/* ************************************************************************** */

bool Fixed::operator>(const Fixed& rhs) const
{
	return _fixedPointNbValue > rhs._fixedPointNbValue;
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return _fixedPointNbValue < rhs._fixedPointNbValue;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return _fixedPointNbValue >= rhs._fixedPointNbValue;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return _fixedPointNbValue <= rhs._fixedPointNbValue;
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return _fixedPointNbValue == rhs._fixedPointNbValue;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return _fixedPointNbValue != rhs._fixedPointNbValue;
}

/* ************************************************************************** */
// 																			  //
// 							  ATITHMETIC OPERATORS							  //
//																	 		  //
/* ************************************************************************** */

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed r;
	r._fixedPointNbValue = _fixedPointNbValue + rhs._fixedPointNbValue;
	return r;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed r;
	r._fixedPointNbValue = _fixedPointNbValue - rhs._fixedPointNbValue;
	return r;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed r;
	long prod = static_cast<long>(_fixedPointNbValue) * rhs._fixedPointNbValue;
	r._fixedPointNbValue = static_cast<int>(prod >> _nbFractionalBits);
	return r;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed r;
	if (rhs._fixedPointNbValue == 0)
	{
		std::cerr << "Division by zero is not possible\n";
		return r;
	}
	long dividend = static_cast<long>(_fixedPointNbValue) << _nbFractionalBits;
	r._fixedPointNbValue = static_cast<int>(dividend / rhs._fixedPointNbValue);
	return r;
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

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	_fixedPointNbValue++;
	return old;
}

Fixed& Fixed::operator--()
{
	_fixedPointNbValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	_fixedPointNbValue--;
	return old;
}

/* ************************************************************************** */
// 																			  //
// 						 	OVERLOAD MEMBER FUNCTIONS						  //
//																	 		  //
/* ************************************************************************** */

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs){
	return lhs < rhs ? lhs : rhs;}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	return lhs < rhs ? lhs : rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
	return lhs > rhs ? lhs : rhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	return lhs > rhs ? lhs : rhs;
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
