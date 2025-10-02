/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_enemy_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:24:33 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/23 17:14:39 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_blocked_error(void)
{
	ft_printf("Error\n \xE2\x88\x9F one or more enemies are blocked ");
	ft_printf("on the map\n");
}

int	is_enemy_mov_poss(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'X')
			{
				if (map[y - 1][x] != '0' && map[y + 1][x] != '0')
					return (print_blocked_error(), 0);
			}
			else if (map[y][x] == 'Y')
			{
				if (map[y][x - 1] != '0' && map[y][x + 1] != '0')
					return (print_blocked_error(), 0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
