/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_enemy_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:24:33 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/03 02:35:02 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Print a generic error about blocked enemies on the map
static void	print_blocked_error(void)
{
	ft_printf("Error\n \xE2\x88\x9F one or more enemies are blocked ");
	ft_printf("on the map\n");
}

// Check along a horizontal corridor if any vertical opening ('0') exists
static int	has_opening_along_row(char **map, int y, int x)
{
	int	w;
	int	lx;
	int	rx;
	int	i;

	w = (int)ft_strlen(map[0]);
	lx = x;
	rx = x;
	while (lx > 0 && map[y][lx - 1] != '1')
		lx--;
	while (rx + 1 < w && map[y][rx + 1] != '1')
		rx++;
	i = lx;
	while (i <= rx)
	{
		if (y > 0 && map[y - 1][i] == '0')
			return (1);
		if (map[y + 1] && map[y + 1][i] == '0')
			return (1);
		i++;
	}
	return (0);
}

// Check along a vertical corridor if any horizontal opening ('0') exists
static int	has_opening_along_col(char **map, int y, int x)
{
	int	h;
	int	uy;
	int	dy;
	int	i;

	h = count_map_lines(map);
	uy = y;
	dy = y;
	while (uy > 0 && map[uy - 1][x] != '1')
		uy--;
	while (dy + 1 < h && map[dy + 1][x] != '1')
		dy++;
	i = uy;
	while (i <= dy)
	{
		if (x > 0 && map[i][x - 1] == '0')
			return (1);
		if (map[i][x + 1] && map[i][x + 1] == '0')
			return (1);
		i++;
	}
	return (0);
}

// Public: ensure enemies can be bypassed; avoid impossible corridors
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
			if (map[y][x] == 'X' && !has_opening_along_row(map, y, x))
				return (print_blocked_error(), 0);
			if (map[y][x] == 'Y' && !has_opening_along_col(map, y, x))
				return (print_blocked_error(), 0);
			x++;
		}
		y++;
	}
	return (1);
}
