/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:51:35 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/24 14:14:38 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex(unsigned long n)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16);
	ft_putchar_fd("0123456789abcdef"[n % 16], 1);
}

static int	handle_precision(int count, t_flags f, int l, unsigned long p)
{
	if (f.precision > l)
		l = f.precision;
	if (f.precision != 0 || p != 0)
	{
		if (p == 0)
			write(1, "(nil)", 5);
		else
			ft_putnbr_hex(p);
		count += l;
	}
	return (count);
}

static int	check_minus(int count, t_flags flags, int len, char pad)
{
	if (!flags.minus)
	{
		while (count < flags.width - len - 2)
		{
			write(1, &pad, 1);
			count++;
		}
		write(1, "0x", 2);
		count += 2;
	}
	return (count);
}

static int	check_dotzero(int count, t_flags f, int len, unsigned long p)
{
	char	pad;

	if (p == 0)
	{
		if (f.precision != 0)
			write(1, "0x", 2);
		count += 3;
		while (count < f.width)
		{
			write(1, " ", 1);
			count++;
		}
		return (count);
	}
	if (f.zero && !f.minus)
		pad = '0';
	else
		pad = ' ';
	check_minus(count, f, len, pad);
	return (count);
}

int	print_ptr(void *ptr, t_flags flags)
{
	int					count;
	int					len;
	unsigned long		tmp;
	unsigned long		add;

	if (!ptr)
		return (print_str("(nil)", flags));
	add = (unsigned long)ptr;
	count = 0;
	len = (ptr == 0);
	tmp = add;
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	count = check_dotzero(count, flags, len, add);
	count = handle_precision(count, flags, len, add);
	count += 2;
	return (count);
}
