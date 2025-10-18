/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 06:39:00 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:39:10 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	safe_destroy_image(void *mlx, void **img)
{
	if (mlx && img && *img)
	{
		mlx_destroy_image(mlx, *img);
		*img = NULL;
	}
}

void	free_player_sprites(t_game *game)
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

void	free_map_and_enemies_sprites(t_game *game)
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
