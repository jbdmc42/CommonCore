/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:10:36 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/22 12:11:17 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(int n)
{
	int	len;

	len = (n == 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	print_padding(char c, int times)
{
	int	count;

	count = 0;
	while (times-- > 0)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}

static int	print_sign(int *n, t_flags flags, int *special)
{
	int	count;

	count = 0;
	if (*n < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		if (*n == -2147483648)
			*special = 1;
		else
			*n = -(*n);
	}
	else if (flags.plus)
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	else if (flags.space)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

static int	print_nbr(int n, int special)
{
	int	count;

	count = 0;
	if (special == 1)
	{
		write(1, "2147483648", 10);
		return (10);
	}
	if (n > 9)
		count += print_nbr(n / 10, special);
	ft_putchar_fd((n % 10) + '0', 1);
	count++;
	return (count);
}

int	print_int(int n, t_flags flags)
{
	int	count;
	int	len;
	int	special;

	special = 0;
	count = 0;
	len = nbr_len(n);
	if (flags.dot && flags.precision == 0 && n == 0)
		len = 0;
	if (!flags.minus && (!flags.zero || flags.dot))
		count += print_padding(' ', flags.width
				- (len + (flags.plus || flags.space || n < 0)));
	count += print_sign(&n, flags, &special);
	if (special)
		len = 10;
	if (!flags.minus && flags.zero && !flags.dot)
		count += print_padding('0', flags.width
				- (len + (flags.plus || flags.space || n < 0)));
	count += print_padding('0', flags.precision - len);
	if (!(flags.dot && flags.precision == 0 && n == 0))
		count += print_nbr(n, special);
	if (flags.minus)
		count += print_padding(' ', flags.width - count);
	return (count);
}
