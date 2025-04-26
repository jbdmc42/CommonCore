/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:51:30 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/24 15:51:00 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	check_zeroflag(t_flags flags)
{
	char	pad;

	if (flags.zero && !flags.minus)
		pad = '0';
	else
		pad = ' ';
	return (pad);
}

int	print_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		ft_putchar_fd('%', 1);
		count++;
		while (count < flags.width)
		{
			ft_putchar_fd(' ', 1);
			count++;
		}
	}
	else
	{
		while (count < flags.width - 1)
		{
			ft_putchar_fd(check_zeroflag(flags), 1);
			count++;
		}
		ft_putchar_fd('%', 1);
		count++;
	}
	return (count);
}
