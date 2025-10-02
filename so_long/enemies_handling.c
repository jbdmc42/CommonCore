/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:54:12 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/30 12:13:17 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_enemies(t_game *game, int frame)
{
	int	i;

	if (frame % 600 != 0)
		return ;
	i = 0;
	while (i < game->enemy_num)
	{
		move_enemy(game, &game->enemy_counter[i]);
		i++;
	}
}

void	define_enemy_movement(t_game *game, int count)
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
				game->enemy_counter[count].enemy_axis = get_ea(game->map[y][x]);
				game->enemy_counter[count].enemy_dir = 1;
				count++;
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_game *game)
{
	int	count;

	count = count_enemies_on_map(game);
	game->enemy_num = count;
	if (count > 0)
	{
		game->enemy_counter = malloc(sizeof(t_enemy_counter) * count);
		if (!game->enemy_counter)
		{
			ft_printf("Error\n \xE2\x88\x9F failed to allocate ");
			ft_printf("enemy counter\n");
			exit(1);
		}
		define_enemy_movement(game, 0);
	}
	else
		game->enemy_counter = NULL;
}

static int	is_valid_enemy_move(t_game *game, char tile)
{
	if (tile == 'P')
	{
		ft_printf("Oh no, you lost! Better luck next time.\n");
		handle_close(game);
	}
	if (tile == '0')
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
	if (!is_valid_enemy_move(game, tile))
	{
		enemy_counter->enemy_dir *= -1;
		return ;
	}
	game->map[enemy_counter->enemy_y][enemy_counter->enemy_x] = '0';
	enemy_counter->enemy_x = new_x;
	enemy_counter->enemy_y = new_y;
	if (enemy_counter->enemy_axis == 0)
		game->map[new_y][new_x] = 'X';
	else
		game->map[new_y][new_x] = 'Y';
}
