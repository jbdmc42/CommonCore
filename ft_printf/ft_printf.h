/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:10:44 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/06 10:11:06 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "libft/libft.h"

// Main Prototypes

int		ft_printf(const char *format, ...);

// Function Prototypes Only

// print_char

int		print_char(char c);

// print_str

int		print_str(char *s);

// print_int

int		print_int(int n);

// print_uint

int		print_uint(unsigned int n);

// print_hex

int		print_hex(unsigned int n, int uppercase);

// print_ptr

int		print_ptr(void *ptr);

// check_flagstype

int		check_flagstype(const char *format, va_list args);

#endif