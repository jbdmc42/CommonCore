/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_input_handling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:52:15 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 17:35:44 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		handle_close(game);
	else if (keycode == KEY_R)
		return(reset_game(game), 0);
	else
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
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	free_map(game->original_map);
	exit(0);
	return (0);
}

void	reset_game(t_game *game)
{
	free_map(game->map);
	game->map = copy_map(game->original_map);
	if (!game->map)
	{
		ft_printf("Error\n \xE2\x88\x9F map reset failed (malloc or copy error)\n");
		handle_close(game);
	}
	find_player_position(game);
	game->moving = 0;
	game->frame_counter = 0;
	game->anim_state = 0;
	game->dir = DIR_DOWN;
	game->elements.e_collectible = game->elements.e_total_collectibles;
	ft_printf("Game has been reset\n");
	render_map(game);
}
