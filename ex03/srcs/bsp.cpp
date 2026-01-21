/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:48:20 by erpascua          #+#    #+#             */
/*   Updated: 2026/01/21 14:13:40 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

// Double Aire Signée = (x_2 - x_1)(y_3 - y_1) - (x_3 - x_1)(y_2 - y_1)

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
	Fixed pab = (a.getX() - point.getX()) * (b.getY() - point.getY()) - (b.getX() - point.getX()) * (a.getY() - point.getY());
	Fixed pbc = (b.getX() - point.getX()) * (c.getY() - point.getY()) - (c.getX() - point.getX()) * (b.getY() - point.getY());
	Fixed pca = (c.getX() - point.getX()) * (a.getY() - point.getY()) - (a.getX() - point.getX()) * (c.getY() - point.getY());
	
	Fixed tmp = Fixed(0);

	// Verif: triangle ?
	if (abc == tmp)
	{
		std::cout	<< "Error: Not a triangle\n";
		return false;
	}
	// Verif: on edge ?
	if (pab == tmp || pbc == tmp || pca == tmp)
	{
		std::cout	<< "Error: Point is on the edge\n";
		return false;
	}
	// Verif: all values are pos
	bool sameSignPos = (abc > 0 && pab > 0 && pbc > 0 && pca > 0);
	// Verif: all values are neg
	bool sameSignNeg = (abc < 0 && pab < 0 && pbc < 0 && pca < 0);
	return sameSignPos || sameSignNeg;
}
