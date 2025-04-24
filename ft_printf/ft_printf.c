/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:10:17 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/22 18:36:51 by joaobarb         ###   ########.fr       */
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

/* int main(void)
{
	int a = -1;
	int b = 1;
	int c = 15;
	int d = 16;
	int e = 17;
	int f = 0;
	ft_printf(" %p ", &a);
	ft_printf(" %p ", &b);
	ft_printf(" %p ", &c);
	ft_printf(" %p ", &d);
	ft_printf(" %p ", &e);
	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p ", INT_MIN, INT_MAX);
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	ft_printf(" %p %p ", &f, &f);

	printf(" %p ", -1);
	printf(" %p ", 1);
	printf(" %p ", 15);
	printf(" %p ", 16);
	printf(" %p ", 17);
	printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf(" %p %p ", INT_MIN, INT_MAX);
	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf(" %p %p ", 0, 0);
	return (0);
} */