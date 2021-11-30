/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:23:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/30 18:40:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class	Point
{
	public:
		// Constructors
		Point(void);
		Point(Point const &point);
		Point(float const x, float const y);
		// Destructor
		~Point(void) {};
		// Assignment operator
		Point	&operator=(Point const &point);
		// Getters
		Fixed const	&getX(void) const;
		Fixed const	&getY(void) const;
	private:
		Fixed const	_x;
		Fixed const	_y;
};

// Insertion operator
std::ostream	&operator<<(std::ostream &ostream, Point const &point);

// bsp.cpp
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
