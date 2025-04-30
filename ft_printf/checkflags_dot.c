/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:08:46 by jbdmc             #+#    #+#             */
/*   Updated: 2025/04/29 12:50:19 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkflags_doti(t_flags flags, int n, int count)
{
	
}

int	checkflags_dots(t_flags flags, char *s, int count)
{
	int	len;
	int	i;

	len = flags.precision;
	i = 0;
	if (!flags.minus && flags.dot)
	{
		while (s[i] && i < count && i < len)
		{
			write(1, &s[i], 1);
			i++;
		}
		return (i);
	}
	return (0);
}
