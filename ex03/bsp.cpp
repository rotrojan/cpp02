/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:30:55 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/30 23:42:28 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	point_are_collinear(Point const a, Point const b, Point const c)
{
	return (a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY()) == 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point_are_collinear(a, b, c) == true)
		return (false);
	Fixed	quotient_w1(
			(b.getY() - a.getY()) * (c.getX() - a.getX())
				- (b.getX() - a.getX()) * (c.getY() - a.getY())
	);
	Fixed	quotient_w2(c.getY() - a.getY());
	if (quotient_w1 == 0 || quotient_w2 == 0)
		return (bsp(c, a, b, point));
	Fixed	w1(
		(a.getX() * (c.getY() - a.getY())
			+ (point.getY() - a.getY()) * (c.getX() - a.getX())
			- point.getX() * (c.getY() - a.getY()))
		/ quotient_w1
	);
	Fixed	w2(
		(point.getY() - a.getY() - w1 * (b.getY() - a.getY()))
		/ quotient_w2
	);
	return (w1 > 0 && w2 > 0 && w1 + w2 < 1);
}
