/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:54:24 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:39:53 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Check if a move is allowed considering walls and exit rules
int	is_move_valid(char tile)
{
	if (tile == '1')
		return (0);
	return (1);
}

// Handle picking up a collectible and update counters
void	handle_collectible(t_game *game, int x, int y)
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

// Update the player's position and move counter
void	update_player_position(t_game *game, int new_x, int new_y)
{
	char	dest;

	dest = game->map[new_y][new_x];
	if (game->player_on_exit)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	if (dest == 'E' && game->elements.e_collectible > 0)
		game->player_on_exit = 1;
	else
		game->player_on_exit = 0;
	game->map[new_y][new_x] = 'P';
	game->move_counter++;
}

// Log the last movement performed with source and destination
static void	log_player_move(t_game *game, int old_x, int old_y)
{
	ft_printf("Moved from [%d , %d] to [%d , %d] --> Move %i\n",
		old_x, old_y, game->player_x, game->player_y, game->move_counter);
}

// Try to move player and handle win/blocked cases
void	try_move_player(int dx, int dy, t_game *game)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	tile = game->map[new_y][new_x];
	if (!is_move_valid(tile))
	{
		game->moving = 0;
		return ;
	}
	game->moving = 1;
	if (tile == 'E' && game->elements.e_collectible == 0)
	{
		ft_printf("Congratulations, you won!\n Total moves: %i\n",
			game->move_counter);
		handle_close(game);
		return ;
	}
	player_movement_wrapper(game, tile, new_x, new_y);
	log_player_move(game, game->player_x - dx, game->player_y - dy);
	game->moving = 0;
	game->player_sprite = game->player.idle[game->dir];
	game->move_delay = MOVE_DELAY;
}
