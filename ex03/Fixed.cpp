/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:26:44 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/29 20:31:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* ************************************************************************** */
// Constructors
/* ************************************************************************** */

Fixed::Fixed(void): _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const &val): _rawBits(val << _fractBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const &val): _rawBits(roundf(val * (1 << _fractBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

/* ************************************************************************** */
// Destructor
/* ************************************************************************** */

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
// Assignation operator
/* ************************************************************************** */

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = fixed.getRawBits();
	return (*this);
}

/* ************************************************************************** */
// Comparison operators
/* ************************************************************************** */

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->_rawBits < fixed.getRawBits());
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->_rawBits > fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->_rawBits <= fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->_rawBits >= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->_rawBits == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->_rawBits != fixed.getRawBits());
}

/* ************************************************************************** */
// Arithmetic operators
/* ************************************************************************** */

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	Fixed	tmp;

	tmp.setRawBits(((int64_t)this->getRawBits() * (int64_t)fixed.getRawBits()) / (1 << _fractBits));
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed	tmp;

	tmp.setRawBits(((int64_t)this->getRawBits() * (1 << _fractBits)) / fixed.getRawBits());
	return (tmp);
}

/* ************************************************************************** */
// Unary operators
/* ************************************************************************** */

Fixed	&Fixed::operator++(void)
{
	this->_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_rawBits += 1;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_rawBits -= 1;
	return (tmp);
}

/* ************************************************************************** */
// Insertion operator
/* ************************************************************************** */

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/* ************************************************************************** */
// Insertion operator
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &ostream, Fixed const &fixed)
{
	// std::cout << "Insertion operator called" << std::endl;
	ostream << fixed.toFloat();
	return (ostream);
}

/* ************************************************************************** */
// Getters
/* ************************************************************************** */

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

/* ************************************************************************** */
// Setter
/* ************************************************************************** */

void	Fixed::setRawBits(int const rawBits)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = rawBits;
}
