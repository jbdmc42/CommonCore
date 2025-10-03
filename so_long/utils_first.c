/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:48:36 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/03 01:09:33 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement_wrapper(t_game *game, char tile, int new_x, int new_y)
{
	check_for_enemies(game, tile);
	update_player_direction(game, new_x, new_y);
	update_animation(game);
	handle_collectible(game, new_x, new_y);
	update_player_position(game, new_x, new_y);
}

void	check_for_enemies(t_game *game, char tile)
{
	if (tile == 'X' || tile == 'Y')
	{
		ft_printf("Oh no, you lost! Better luck next time.\n");
		handle_close(game);
		return ;
	}
}
