/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:09:15 by erpascua          #+#    #+#             */
/*   Updated: 2026/01/21 14:15:32 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main()
{
	Point a(1000000.0f, 1000000.0f);
	Point b(1000000.1f, 1000000.2f);
	Point c(1000000.05f, 1000001.0f);
	Point point(1000000.05f, 1000000.15f);

	if (bsp(a, b, c, point))
		std::cout	<< "The point is inside the triangle\n";
	else
		std::cout	<< "The point is outside the triangle or on its segments\n";
}
