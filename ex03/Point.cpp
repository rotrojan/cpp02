/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:11:05 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/29 23:27:49 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
}

Point::Point(Point const &point): _x(point.getX()), _y(point.getY())
{
}

Point::Point(float const x, float const y): _x(Fixed(x)), _y(Fixed(y))
{
}

Point	&Point::operator=(Point const &point)
{
	// After some research, there is no way to cleanly modify a const value in a CPP classes.
	// There is still the possibility to do a cast, but that is kind of ugly.
	// This overload is useless, but compliant with the subject ... ¯\_(ツ)_/¯
	(void)point;
	return (*this);
}

Fixed const	&Point::getX(void) const
{
	return (this->_x);
}

Fixed const	&Point::getY(void) const
{
	return (this->_y);
}
