/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_input_handling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:52:15 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/30 16:52:39 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
	{
		ft_printf("Game closed successfully by player input.\n");
		handle_close(game);
	}
	else if (keycode == KEY_R)
		return (reset_game(game), 0);
	else if (game->move_delay == 0)
	{
		check_correct_player_input(keycode, game);
		game->moving = 1;
	}
	render_map(game);
	return (0);
}

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_all_and_exit(game);
	free_map(game->map);
	free_map(game->original_map);
	exit(0);
	return (0);
}

static void	clear_enemies(t_game *game)
{
	if (game->enemy_counter)
	{
		free(game->enemy_counter);
		game->enemy_counter = NULL;
	}
	game->enemy_num = 0;
}

static void	reset_vars(t_game *game)
{
	game->moving = 0;
	game->frame_counter = 0;
	game->anim_state = 0;
	game->dir = DIR_DOWN;
	game->move_counter = 0;
	game->elements.e_collectible = game->elements.e_total_collectibles;
	game->move_delay = 0;
}

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
