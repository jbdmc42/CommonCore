/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:52:10 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/26 16:30:35 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex(n / 16, uppercase);
	ft_putchar_fd(base[n % 16], 1);
}

static void	print_hex_prefix(int uppercase)
{
	if (uppercase)
		ft_putstr_fd("0X", 1);
	else
		ft_putstr_fd("0x", 1);
}

static int count_hex(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	check_prealiwdt(t_flags flags, int count)
{
	if (!flags.minus && flags.width > count)
	{
		if (flags.zero && !flags.dot)
			return (print_padding('0', flags.width - count));
		else if (flags.width)
			return (print_padding(' ', flags.width - count));
	}
	return (0);
}

int	print_hex(unsigned int n, int uppercase, t_flags flags)
{
	int				len;
	int				count;
	int				prefix;

	prefix = 0;
	if (flags.hashtag && n != 0)
		prefix = 2;
	len = count_hex(n);
	if (flags.dot && flags.precision == 0 && n == 0)
		len = 0;
	count = len;
	if (flags.precision > len)
		count = flags.precision;
	count += check_prealiwdt(flags, count) + prefix;
	if (prefix)
		print_hex_prefix(uppercase);
	if (flags.precision > len)
		count += print_padding('0', flags.precision - len);
	if (!(flags.dot && flags.precision == 0 && n == 0))
		ft_putnbr_hex(n, uppercase);
	if (flags.width > count)
		return (flags.width);
	return (count);
}
