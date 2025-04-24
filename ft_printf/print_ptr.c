/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:51:35 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/22 18:45:32 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex(unsigned long long n)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16);
	ft_putchar_fd("0123456789abcdef"[n % 16], 1);
}

static int	handle_precision(int count, t_flags f, int l, unsigned long long p)
{
	if (f.precision > l)
		l = f.precision;
	if (f.precision != 0 || p != 0)
	{
		if (p == 0)
			write(1, "0", 1);
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

static int	check_dotzero(int count, t_flags f, int len, unsigned long long p)
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

int	print_ptr(unsigned long long ptr, t_flags flags)
{
	int					count;
	int					len;
	unsigned long long	tmp;

	count = 0;
	len = 0;
	if (ptr == 0)
		len = 1;
	else
	{
		tmp = ptr;
		while (tmp)
		{
			tmp /= 16;
			len++;
		}
	}
	count = check_dotzero(count, flags, len, ptr);
	count = handle_precision(count, flags, len, ptr);
	return (count);
}
