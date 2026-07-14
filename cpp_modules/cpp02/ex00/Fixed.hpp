#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		// 1. Orthodox Canonical Form elements
		Fixed( void );							// default constructor
		Fixed( const Fixed &src );				// copy constructor
		Fixed &operator=( const Fixed &rhs );	// copy assignment operator
		~Fixed( void );							// defautl destructor

		// 2. Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif