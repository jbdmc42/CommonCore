/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 00:45:00 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/08 12:19:52 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Clear enemy tracking array and reset enemy count
static void	clear_enemies(t_game *game)
{
	if (game->enemy_counter)
	{
		free(game->enemy_counter);
		game->enemy_counter = NULL;
	}
	game->enemy_num = 0;
}

// Reset runtime variables related to movement and animations
static void	reset_vars(t_game *game)
{
	game->moving = 0;
	game->frame_counter = 0;
	game->anim_state = 0;
	game->dir = DIR_DOWN;
	game->move_counter = 0;
	game->elements.e_collectible = game->elements.e_total_collectibles;
	game->move_delay = 0;
	game->player_on_exit = 0;
}

// Reset game state to original map, reinit enemies and re-render
void	reset_game(t_game *game)
{
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	game->map = copy_map(game->original_map);
	if (!game->map)
	{
		ft_printf("Error\n \xE2\x88\x9F map reset failed ");
		ft_printf("(malloc or copy error)\n");
		handle_close(game);
	}
	clear_enemies(game);
	init_enemies(game);
	find_player_position(game);
	reset_vars(game);
	ft_printf("Game has been reset.\n");
	render_map(game);
}
