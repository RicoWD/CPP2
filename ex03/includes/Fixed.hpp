/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:57:12 by ep                #+#    #+#             */
/*   Updated: 2026/01/20 02:46:25 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Fixed
{
    public:
		// Orthodox Canonical Form 
        Fixed();
        Fixed(const Fixed &cpy);
        Fixed &operator=(const Fixed &cpy);
        Fixed(const int intToConvert);
        Fixed(const float floatToConvert);
        ~Fixed();

		// Member functions
        int   getRawBits() const;
        void  setRawBits(int const raw);
        float toFloat() const;
        int   toInt() const;

		// Comparison operators
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		// Increment/Decrement operators
		Fixed& operator++();
		Fixed operator++(int n);
		Fixed& operator--();
		Fixed operator--(int n);

		// Overload member functions
		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);


    private:
        int              _fixedPointNbValue;
        static const int _nbFractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);