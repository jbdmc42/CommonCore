#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=( const Fixed &rhs ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_rawBits = rhs.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int intVal) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = intVal << _fractionalBits;
}

Fixed::Fixed( const float floatVal) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(floatVal * (1 << _fractionalBits));
}

int Fixed::getRawBits( void ) const {
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

float Fixed::toFloat( void ) const {
	return ((float)this->_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const {
	return (this->_rawBits >> _fractionalBits);
}

std::ostream &operator<<( std::ostream &out, const Fixed &fixed ) {
	out << fixed.toFloat();
	return (out);
}

// Operator overload functions

bool Fixed::operator>( const Fixed &rhs) const {
	return (this->_rawBits > rhs.getRawBits());
}

bool Fixed::operator<( const Fixed &rhs) const {
	return (this->_rawBits < rhs.getRawBits());
}

bool Fixed::operator>=( const Fixed &rhs) const {
	return (this->_rawBits >= rhs.getRawBits());
}

bool Fixed::operator<=( const Fixed &rhs) const {
	return (this->_rawBits <= rhs.getRawBits());
}

bool Fixed::operator==( const Fixed &rhs) const {
	return (this->_rawBits == rhs.getRawBits());
}

bool Fixed::operator!=( const Fixed &rhs) const {
	return (this->_rawBits != rhs.getRawBits());
}

Fixed Fixed::operator+( const Fixed &rhs ) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-( const Fixed &rhs ) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*( const Fixed &rhs ) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/( const Fixed &rhs ) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++( void ) {
	this->_rawBits += 1;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	Fixed temp(*this);
	this->_rawBits += 1;
	return (temp);
}

Fixed &Fixed::operator--( void ) {
	this->_rawBits -= 1;
	return (*this);
}

Fixed Fixed::operator--( int ) {
	Fixed temp(*this);
	this->_rawBits -= 1;
	return (temp);
}

// Static Min / Max functions
Fixed &Fixed::min( Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b) {
	return ((a < b) ? a : b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b) {
	return ((a > b) ? a : b);
}