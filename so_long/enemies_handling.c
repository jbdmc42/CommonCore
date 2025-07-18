/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:54:12 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/18 11:23:02 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_enemies(t_game *game, int frame)
{
	int	i;

	if (frame % 300 != 0)
		return ;
	i = 0;
	while (i < game->enemy_num)
	{
		move_enemy(game, &game->enemy_counter[i]);
		i++;
	}
}

static void	define_enemy_movement(t_game *game, int count)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'X' || game->map[y][x] == 'Y')
			{
				game->enemy_counter[count].enemy_x = x;
				game->enemy_counter[count].enemy_y = y;
				game->enemy_counter[count].enemy_axis = get_enemy_axis(game->map[y][x]);
				game->enemy_counter[count].enemy_dir = 1;
				game->map[y][x] = 'X';
				count++;
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_game *game)
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
	game->enemy_num = count;
	game->enemy_counter = malloc(sizeof(t_enemy_counter) * count);
	if (!game->enemy_counter)
		return ;
	define_enemy_movement(game, 0);
}

static int	is_valid_enemy_move(char tile)
{
	if (tile == '0' || tile == 'P')
		return (1);
	return (0);	
}

void	move_enemy(t_game *game, t_enemy_counter *enemy_counter)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = enemy_counter->enemy_x;
	new_y = enemy_counter->enemy_y;
	if (enemy_counter->enemy_axis == 0)
		new_y += enemy_counter->enemy_dir;
	else
		new_x += enemy_counter->enemy_dir;
	tile = game->map[new_y][new_x];
	if (!is_valid_enemy_move(tile))
	{
		enemy_counter->enemy_dir *= -1;
		return ;
	}
	game->map[enemy_counter->enemy_y][enemy_counter->enemy_x] = '0';
	enemy_counter->enemy_x = new_x;
	enemy_counter->enemy_y = new_y;
	game->map[new_y][new_x] = 'X';
}
