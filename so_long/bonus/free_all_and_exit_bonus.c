/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_and_exit_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:57:03 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:39:04 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_enemy_counter(t_game *game)
{
	if (game->enemy_counter)
	{
		free(game->enemy_counter);
		game->enemy_counter = NULL;
	}
}

void	free_maps(t_game *game)
{
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	if (game->original_map)
	{
		free_map(game->original_map);
		game->original_map = NULL;
	}
}

void	free_map_name(t_game *game)
{
	if (game->map_name)
	{
		free(game->map_name);
		game->map_name = NULL;
	}
}

void	destroy_window_and_mlx(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

// Entry point for cleaning up all resources and exiting
void	free_all_and_exit(t_game *game)
{
	free_player_sprites(game);
	free_collectible_sprites(game);
	free_map_and_enemies_sprites(game);
	free_enemy_counter(game);
	free_maps(game);
	free_map_name(game);
	destroy_window_and_mlx(game);
	exit(0);
}
