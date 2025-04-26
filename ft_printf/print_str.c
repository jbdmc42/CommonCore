/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:10:30 by joaobarb          #+#    #+#             */
/*   Updated: 2025/04/24 12:56:57 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_spaces(int count, t_flags flags, int len)
{
	while (count < flags.width - len)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int	print_str(char *s, t_flags flags)
{
	int	count;
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags.dot && flags.precision < len)
		len = flags.precision;
	count = 0;
	if (!flags.minus)
		count += print_spaces(count, flags, len);
	write(1, s, len);
	count += len;
	if (flags.minus)
		count += print_spaces(count, flags, len);
	return (count);
}
