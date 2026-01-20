/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:48:20 by erpascua          #+#    #+#             */
/*   Updated: 2026/01/20 20:00:40 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

// Double Aire Signée = (x_2 - x_1)(y_3 - y_1) - (x_3 - x_1)(y_2 - y_1)

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX) * (b.getY() - a.getY());
	Fixed pab = (a.getX() - p.getX()) * (b.getY() - p.getY()) - (b.getX() - p.getX) * (a.getY() - p.getY());
	Fixed pbc = (b.getX() - p.getX()) * (c.getY() - p.getY()) - (c.getX() - p.getX) * (b.getY() - p.getY());
	Fixed pca = (b.getX() - p.getX()) * (c.getY() - p.getY()) - (c.getX() - p.getX) * (b.getY() - p.getY());
	
	std::cout	<< "ABC = "	<< abc << "\n"
				<< "PAB = " << pab << "\n"
				<< "PBC = " << pbc << "\n"
				<< "PCA = " << pca << "\n";
	
	

	return (true);
}
