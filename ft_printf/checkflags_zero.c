/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:56:10 by jbdmc             #+#    #+#             */
/*   Updated: 2025/04/28 10:03:11 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkflags_zero(t_flags flags, int n, int count)
{
	if (!flags.minus && flags.zero && flags.width > count)
	{
		if (!flags.dot)
			return (print_padding('0', flags.width - count));
		else if (flags.width)
			return (print_padding(' ', flags.width - count));
	}
	return (0);
}