/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ep <ep@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:48:20 by erpascua          #+#    #+#             */
/*   Updated: 2026/01/21 05:14:09 by ep               ###   ########.fr       */
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
	
	if (pab == 0 || pbc == 0 || pca == 0)
		return false;
	
	bool sameSignPos = (abc > 0 && pab > 0 && pbc > 0 && pca > 0);
	bool sameSignNeg = (abc < 0 && pab < 0 && pbc < 0 && pca < 0);
	return sameSignPos || sameSignNeg;
}
