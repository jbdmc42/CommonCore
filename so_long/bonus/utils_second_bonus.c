/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:37:11 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:40:57 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_walls(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			j = 0;
			while (j < width)
				if (map[i][j++] != '1')
					return (0);
		}
		else
		{
			if (map[i][0] != '1' || map[i][width - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

static void	init_vars_two(t_game *game)
{
	game->collectible.frames[0] = NULL;
	game->collectible.frames[1] = NULL;
	game->collectible.frames[2] = NULL;
	game->collectible.frames[3] = NULL;
	game->collectible.frames[4] = NULL;
	game->collectible.frames[5] = NULL;
	game->collectible.frames[6] = NULL;
	game->collectible.frames[7] = NULL;
	game->collectible.frames[8] = NULL;
	game->img_ground = NULL;
	game->img_wall = NULL;
	game->enemies.frames[0] = NULL;
	game->enemies.frames[1] = NULL;
	game->enemies.frames[2] = NULL;
	game->exit.frames[0] = NULL;
	game->exit.frames[1] = NULL;
	game->exit.frames[2] = NULL;
	game->exit.frames[3] = NULL;
	game->exit.frames[4] = NULL;
	game->exit.frames[5] = NULL;
	game->exit.frames[6] = NULL;
	game->exit.frames[7] = NULL;
	game->exit.frames[8] = NULL;
	game->exit.frames[9] = NULL;
	game->exit.frames[10] = NULL;
}

void	init_vars(t_game *game)
{
	game->player_sprite = NULL;
	game->frame_counter = 0;
	game->anim_state = 0;
	game->dir = DIR_DOWN;
	game->player_x = 0;
	game->player_y = 0;
	game->move_counter = 0;
	game->move_delay = 0;
	game->collectible_frame = 0;
	game->enemy_frame = 0;
	game->exit_frame = 0;
	game->player.idle[DIR_UP] = NULL;
	game->player.idle[DIR_DOWN] = NULL;
	game->player.idle[DIR_LEFT] = NULL;
	game->player.idle[DIR_RIGHT] = NULL;
	game->player.move1[DIR_UP] = NULL;
	game->player.move1[DIR_DOWN] = NULL;
	game->player.move1[DIR_LEFT] = NULL;
	game->player.move1[DIR_RIGHT] = NULL;
	game->player.move2[DIR_UP] = NULL;
	game->player.move2[DIR_DOWN] = NULL;
	game->player.move2[DIR_LEFT] = NULL;
	game->player.move2[DIR_RIGHT] = NULL;
	game->player_on_exit = 0;
	init_vars_two(game);
}

char	*prepare_moves_str(t_game *game)
{
	char	*tmp;
	char	*moves_str;

	moves_str = ft_itoa(game->move_counter);
	tmp = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	return (tmp);
}

void	print_idle_error(int j)
{
	ft_printf("Error\n \xE2\x88\x9F player ");
	ft_printf("idle frame %i is NULL\n", j);
}
