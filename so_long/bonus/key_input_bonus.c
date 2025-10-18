/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 02:10:00 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:39:21 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Handle keyboard input: close, reset and move; then render
int	handle_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
	{
		handle_close_user(game);
		return (0);
	}
	else if (keycode == KEY_R)
	{
		reset_game(game);
		return (0);
	}
	else if (game->move_delay == 0)
	{
		check_correct_player_input(keycode, game);
		game->moving = 1;
	}
	render_map(game);
	return (0);
}
