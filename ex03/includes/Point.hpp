/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 02:51:24 by ep                #+#    #+#             */
/*   Updated: 2026/01/21 05:00:22 by ep               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		// Orthodox Canocical Form 
		Point();
		Point(const float nX, const float nY);
		Point(const Point& cpy);
		Point& operator=(const Point& old);
		~Point();

		// Get
		Fixed getX(void) const;
		Fixed getY(void) const; 
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
