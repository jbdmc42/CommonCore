/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:54:24 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 18:48:53 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_move_valid(char tile, t_game *game)
{
	if (tile == '1')
		return (0);
	if (tile == 'E' && game->elements.e_collectible > 0)
	{
		ft_printf("You can only finish the level after grabbing all the ");
		ft_printf("collectibles on the map!\n");
		return (0);
	}
	return (1);
}

static void	handle_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->elements.e_collectible--;
		game->map[y][x] = '0';
		ft_printf("+1 collectible [%d/%d]\n",
			game->elements.e_total_collectibles - game->elements.e_collectible,
			game->elements.e_total_collectibles);
		if (game->elements.e_collectible == 0)
		{
			ft_printf("You have grabbed all the collectibles on the map! ");
			ft_printf("You can now exit the level.\n");
		}
	}
}

static void	log_player_move(t_game *game, int old_x, int old_y)
{
	ft_printf("Moved from [%d , %d] to [%d , %d]\n", old_x, old_y,
		game->player_x, game->player_y);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
}

void	try_move_player(int dx, int dy, t_game *game)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	tile = game->map[new_y][new_x];
	if (!is_move_valid(tile, game))
	{
		game->moving = 0;
		return ;
	}
	if (tile == 'E' && game->elements.e_collectible == 0)
	{
		ft_printf("Congratulations, you won!\n");
		handle_close(game);									// add a display_game_stats to show game stats and pause before closing the game
		return ;
	}
	check_for_enemies(game, tile);
	update_player_direction(game, new_x, new_y);
	update_animation(game);
	handle_collectible(game, new_x, new_y);
	update_player_position(game, new_x, new_y);
	log_player_move(game, game->player_x - dx, game->player_y - dy);
}
