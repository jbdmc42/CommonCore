/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:10:17 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/22 17:23:55 by joaobarb         ###   ########.fr       */
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
	char *s2 = "Hello World!";
	ft_putchar_fd(s2[0], 1);
	ft_printf(" %s ");
	ft_printf(" %s ", "-");
	ft_printf(" %s %s ", "", "-");
	ft_printf(" %s %s ", " - ", "");
	ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	ft_printf(" NULL %s NULL ", NULL);
	return (0);
} */