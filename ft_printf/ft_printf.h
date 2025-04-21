#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"

// Main Prototypes

int	ft_printf(const char *format, ...);

// Flag Struct Prototype

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hashtag;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_flags;

// Function Prototypes Only

// print_char

int	print_char(char c, t_flags flags);

// print_str

int	print_str(char *s, t_flags flags);

// print_int

int	print_int(int n, t_flags flags);

// print_uint

int	print_uint(unsigned int n, t_flags flags);

// print_hex

int	print_hex(unsigned int n, int hex, t_flags flags);

// print_ptr

int	print_ptr(void *ptr, t_flags flags);

// print_percent

int	print_percent(t_flags flags);

#endif