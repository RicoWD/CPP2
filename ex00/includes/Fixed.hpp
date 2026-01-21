/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:55:51 by ep                #+#    #+#             */
/*   Updated: 2026/01/21 14:17:00 by erpascua         ###   ########.fr       */
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