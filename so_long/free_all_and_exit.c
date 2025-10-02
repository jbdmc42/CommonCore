/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:57:03 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/30 12:05:24 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	safe_destroy_image(void *mlx, void **img)
{
	if (*img)
	{
		mlx_destroy_image(mlx, *img);
		*img = NULL;
	}
}

static void	free_player_sprites(t_game *game)
{
	safe_destroy_image(game->mlx, (void **)&game->player.idle[DIR_UP]);
	safe_destroy_image(game->mlx, (void **)&game->player.idle[DIR_DOWN]);
	safe_destroy_image(game->mlx, (void **)&game->player.idle[DIR_LEFT]);
	safe_destroy_image(game->mlx, (void **)&game->player.idle[DIR_RIGHT]);
	safe_destroy_image(game->mlx, (void **)&game->player.move1[DIR_UP]);
	safe_destroy_image(game->mlx, (void **)&game->player.move1[DIR_DOWN]);
	safe_destroy_image(game->mlx, (void **)&game->player.move1[DIR_LEFT]);
	safe_destroy_image(game->mlx, (void **)&game->player.move1[DIR_RIGHT]);
	safe_destroy_image(game->mlx, (void **)&game->player.move2[DIR_UP]);
	safe_destroy_image(game->mlx, (void **)&game->player.move2[DIR_DOWN]);
	safe_destroy_image(game->mlx, (void **)&game->player.move2[DIR_LEFT]);
	safe_destroy_image(game->mlx, (void **)&game->player.move2[DIR_RIGHT]);
}

void	free_collectible_sprites(t_game *game)
{
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[0]);
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[1]);
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[2]);
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[3]);
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[4]);
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[5]);
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[6]);
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[7]);
	safe_destroy_image(game->mlx, (void **)&game->collectible.frames[8]);
}

static void	free_map_and_enemies_sprites(t_game *game)
{
	safe_destroy_image(game->mlx, (void **)&game->img_ground);
	safe_destroy_image(game->mlx, (void **)&game->img_wall);
	safe_destroy_image(game->mlx, (void **)&game->enemies.frames[0]);
	safe_destroy_image(game->mlx, (void **)&game->enemies.frames[1]);
	safe_destroy_image(game->mlx, (void **)&game->enemies.frames[2]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[0]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[1]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[2]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[3]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[4]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[5]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[6]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[7]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[8]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[9]);
	safe_destroy_image(game->mlx, (void **)&game->exit.frames[10]);
}

void	free_all_and_exit(t_game *game)
{
	int	i;

	i = 0;
	free_player_sprites(game);
	free_collectible_sprites(game);
	free_map_and_enemies_sprites(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	free(game->map_name);
	exit(0);
}
