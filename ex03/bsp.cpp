/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:30:55 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/30 18:18:46 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	w1(
		(a.getX() * (c.getY() - a.getY())
			+ (point.getY() - a.getY()) * (c.getX() - a.getX())
			- point.getX() * (c.getY() - a.getY()))
		/ ((b.getY() - a.getY()) * (c.getX() - a.getX())
				- (b.getX() - a.getX()) * (c.getY() - a.getY()))
	);
	Fixed	w2(
		(point.getY() - a.getY() - w1 * (b.getY() - a.getY()))
		/ (c.getY() - a.getY())
	);
	return (w1 > 0 && w2 > 0 && w1 + w2 < 1);
}
