/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags_hashtag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:24:04 by jbdmc             #+#    #+#             */
/*   Updated: 2025/04/28 09:58:45 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkflags_hashtag(t_flags flags, int uppercase, int n, int count)
{
	if (flags.hashtag && n != 0)
	{
		if (uppercase)
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		count += 2;
	}
	return (count);
}