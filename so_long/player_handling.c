/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:45:12 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 18:43:26 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_correct_player_input(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
		try_move_player(0, -1, game);
	else if (keycode == XK_s || keycode == XK_Down)
		try_move_player(0, 1, game);
	else if (keycode == XK_a || keycode == XK_Left)
		try_move_player(-1, 0, game);
	else if (keycode == XK_d || keycode == XK_Right)
		try_move_player(1, 0, game);
}

void    find_player_position(t_game *game)
{
    int y = 0;
    int x;

    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
    game->player_x = -1;
    game->player_y = -1;
}

void    update_player_direction(t_game *game, int new_x, int new_y)
{
    if (new_y < game->player_y)
        game->dir = DIR_UP;
    else if (new_y > game->player_y)
        game->dir = DIR_DOWN;
    else if (new_x < game->player_x)
        game->dir = DIR_LEFT;
    else if (new_x > game->player_x)
        game->dir = DIR_RIGHT;
}