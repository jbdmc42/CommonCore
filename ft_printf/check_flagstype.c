/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flagstype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:10:12 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/22 15:52:24 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	special_cases(const char *format, t_flags *flags, int i)
{
	while (format[i])
	{
		if (format[i] == '.')
		{
			flags->dot = 1;
			i++;
			flags->precision = ft_atoi(format + i);
			while (format[i] && ft_isdigit(format[i]))
				i++;
			continue ;
		}
		else if (ft_isdigit(format[i]))
		{
			flags->width = ft_atoi(format + i);
			while (format[i] && ft_isdigit(format[i]))
				i++;
			continue ;
		}
		else
			break ;
	}
	return (i);
}

static int	parse_flags(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == '#')
			flags->hashtag = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == '.' || ft_isdigit(format[i]))
			i = special_cases(format, flags, i);
		else
			break ;
		i++;
	}
	return (i);
}

int	check_flagstype(const char *format, va_list args)
{
	t_flags	flags;
	int		i;

	i = 0;
	init_flags(&flags);
	i += parse_flags(format + i, &flags);
	if (format[i] == 'c')
		return (print_char((char)va_arg(args, int), flags));
	else if (format[i] == 's')
		return (print_str(va_arg(args, char *), flags));
	else if (format[i] == 'p')
		return (print_ptr(va_arg(args, void *), flags));
	else if (format[i] == 'd' || format[i] == 'i')
		return (print_int(va_arg(args, int), flags));
	else if (format[i] == 'u')
		return (print_uint(va_arg(args, unsigned int), flags));
	else if (format[i] == 'x')
		return (print_hex(va_arg(args, unsigned int), 0, flags));
	else if (format[i] == 'X')
		return (print_hex(va_arg(args, unsigned int), 1, flags));
	else if (format[i] == '%')
		return (print_percent(flags));
	return (0);
}
