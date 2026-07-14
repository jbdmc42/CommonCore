#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		// 1. Orthodox Canonical Form elements
		Fixed( void );							// default constructor
		Fixed( const Fixed &src );				// copy constructor
		Fixed( const int intVal);				// int constructor
		Fixed( const float floatVal);			// float constructor
		Fixed &operator=( const Fixed &rhs );	// copy assignment operator
		~Fixed( void );							// defautl destructor

		// 2. Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		// 3. Operators overload
		bool	operator>( const Fixed &rhs ) const;
		bool	operator<( const Fixed &rhs ) const;
		bool	operator>=( const Fixed &rhs ) const;
		bool	operator<=( const Fixed &rhs ) const;
		bool	operator==( const Fixed &rhs ) const;
		bool	operator!=( const Fixed &rhs ) const;

		Fixed	operator+( const Fixed	&rhs ) const;
		Fixed	operator-( const Fixed	&rhs ) const;
		Fixed	operator*( const Fixed	&rhs ) const;
		Fixed	operator/( const Fixed	&rhs ) const;

		Fixed	&operator++( void );
		Fixed	&operator--( void );

		Fixed	operator++( int );
		Fixed	operator--( int );

		// 4. Static Min / Max functions
		static Fixed		&min( Fixed &a, Fixed &b);
		static const Fixed	&min( const Fixed &a, const Fixed &b);
		static Fixed		&max( Fixed &a, Fixed &b);
		static const Fixed	&max( const Fixed &a, const Fixed &b);
};

// Stream Insertion Operator Overload (Declared outside the class)
std::ostream &operator<<( std::ostream &out, const Fixed &fixed );
#endif