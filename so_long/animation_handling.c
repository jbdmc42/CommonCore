/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:08:42 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/18 11:22:37 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_collectible_animation(t_game *game, int frame)
{
	static int	statec;
	static int	statee;
	static int	initialized;

	if (!initialized)
	{
		statec = 0;
		statee = 0;
		initialized = 1;
	}
	if (frame % 80 == 0)
	{
		statec++;
		if (statec >= 8)
			statec = 0;
		game->collectible.frames[0] = game->collectible.frames[statec];

		statee++;
		if (statee >= 11)
			statee = 0;
		game->exit.frames[0] = game->exit.frames[statee];
	}
}

void	update_enemy_animation(t_game *game, int frame)
{
	static int	current_frame = 0;

	if (frame % 200 == 0)
	{
		current_frame++;
		if (current_frame >= 3)
			current_frame = 0;
		game->enemies.frames[0] = game->enemies.frames[current_frame];
	}
}

void	update_player_animation(t_game *game, int frame)
{
	int	dir = game->dir;

	if (game->moving)
	{
		if (frame % 200 == 0)
		{
			if (game->anim_state == 0)
				game->player_sprite = game->player.move1[dir];
			else
				game->player_sprite = game->player.move2[dir];
			game->anim_state = !game->anim_state;
		}
	}
	else
	{
		game->player_sprite = game->player.idle[dir];
	}
}

void	update_animation(t_game *game)
{
	static int	frame;

	if (++game->frame_counter >= 10)
	{
		game->frame_counter = 0;
		frame++;
		update_enemy_animation(game, frame);
		update_collectible_animation(game, frame);
		update_player_animation(game, frame);
		update_enemies(game, frame);
		render_map(game);
	}
}

int	update_animation_wrapper(void *param)
{
	update_animation((t_game *)param);
	return (0);
}
