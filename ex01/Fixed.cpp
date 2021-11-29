/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:26:44 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/29 16:48:03 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(int const &val): _rawBits(val << _fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const &val): _rawBits(roundf(val * (1 << _fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = fixed.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, Fixed const &fixed)
{
	// std::cout << "Insertion operator called" << std::endl;
	ostream << fixed.toFloat();
	return (ostream);
}

int	Fixed::toInt(void) const
{
	// std::cout << "toInt member function called" << std::endl;
	return (this->_rawBits >> _fractBits);
}

float	Fixed::toFloat(void) const
{
	// std::cout << "toFloat member function called" << std::endl;
	return (((float)this->_rawBits / (float)(1 << _fractBits)));
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const rawBits)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = rawBits;
}
