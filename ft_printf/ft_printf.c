/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:10:17 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/28 10:14:19 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += check_flagstype(format + i, args);
			while (format[i] && !is_type(format[i]))
				i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	printf("printf: %.0s", "HelloWorld");
	/* printf("printf: %#x\n\n", -1);
	printf("printf: %#x\n\n", 2);
	printf("printf: %#x\n\n", -2); */
	/* ft_printf("ft_printf: %x\n\n", LONG_MAX);
	ft_printf("ft_printf: %x\n\n", -1);
	ft_printf("ft_printf: %x\n\n", 2);
	ft_printf("ft_printf: %x\n\n", -2);
	ft_printf("ft_printf: %x\n\n", -3);
	ft_printf("ft_printf: %#x", -1); */
	return (0);
}
