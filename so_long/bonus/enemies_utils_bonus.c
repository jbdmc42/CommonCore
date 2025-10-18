/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:40:00 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:38:55 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_ea(char c)
{
	int	r;

	r = -1;
	if (c == 'X')
		r = 0;
	else if (c == 'Y')
		r = 1;
	return (r);
}

int	count_enemies_on_map(t_game *game)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'X' || game->map[y][x] == 'Y')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
