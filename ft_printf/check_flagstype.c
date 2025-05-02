/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flagstype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:06:04 by joaobarb          #+#    #+#             */
/*   Updated: 2025/05/02 12:31:11 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flagstype(const char *format, va_list args)
{
	if (*format == 'c')
		return (print_char((char)va_arg(args, int)));
	else if (*format == 's')
		return (print_str(va_arg(args, char *)));
	else if (*format == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (print_int(va_arg(args, int)));
	else if (*format == 'u')
		return (print_uint(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (print_hex(va_arg(args, unsigned long int), 0));
	else if (*format == 'X')
		return (print_hex(va_arg(args, unsigned int), 1));
	else if (*format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
