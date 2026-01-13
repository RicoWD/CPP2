/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:55:51 by ep                #+#    #+#             */
/*   Updated: 2026/01/13 18:50:57 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <string>

class Fixed
{
	public:	
		Fixed();
		Fixed(const Fixed &cpy);
		Fixed &operator = (const Fixed &cpy);
		~Fixed();
		
		int					getRawBits() const;
		void				setRawBits(int const raw);
	
	private:
		int					_fixedPointNbValue;
		const static int	_nbFractionalBits = 8;

};