/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 02:51:24 by ep                #+#    #+#             */
/*   Updated: 2026/01/20 18:59:18 by erpascua         ###   ########.fr       */
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
		Fixed getX(void);
		Fixed getY(void); 
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
