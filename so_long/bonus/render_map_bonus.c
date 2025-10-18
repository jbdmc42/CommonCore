/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:06:44 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:40:08 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Draw a single tile at map (x,y) to the window
void	render_tile(t_game *game, char tile, int x, int y)
{
	int	px;
	int	py;

	px = x * 36;
	py = y * 36;
	mlx_put_image_to_window(game->mlx, game->win, game->img_ground, px, py);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, px, py);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.frames[game->exit_frame], px, py);
	else if (tile == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_sprite, px, py);
	}
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.frames[game->collectible_frame], px, py);
	else if (tile == 'X' || tile == 'Y')
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemies.frames[game->enemy_frame], px, py);
}

// Draw the full map by iterating through all tiles
void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
