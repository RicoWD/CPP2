/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:57:12 by ep                #+#    #+#             */
/*   Updated: 2026/01/14 19:37:19 by erpascua         ###   ########.fr       */
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
        Fixed();
        Fixed(const Fixed &cpy);
        Fixed &operator=(const Fixed &cpy);
        Fixed(const int intToConvert);
        Fixed(const float floatToConvert);
        ~Fixed();

        int   getRawBits() const;
        void  setRawBits(int const raw);
        float toFloat() const;
        int   toInt() const;

		bool operator>(const Fixed& rhs);
		bool operator<(const Fixed& rhs);
		bool operator>=(const Fixed& rhs);
		bool operator<=(const Fixed& rhs);
		bool operator+(const Fixed& rhs);
		bool operator+(const Fixed& rhs);
		bool operator+(const Fixed& rhs);

    private:
        int              _fixedPointNbValue;
        static const int _nbFractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);