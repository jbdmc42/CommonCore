/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:08:42 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/03 01:39:40 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Advance collectible and exit frame indices over time
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
		if (statec >= 9)
			statec = 0;
		game->collectible_frame = statec;
		statee++;
		if (statee >= 11)
			statee = 0;
		game->exit_frame = statee;
	}
}

// Advance enemy animation frame index on schedule
void	update_enemy_animation(t_game *game, int frame)
{
	static int	current_frame = 0;

	if (frame % 200 == 0)
	{
		current_frame++;
		if (current_frame >= 3)
			current_frame = 0;
		game->enemy_frame = current_frame;
	}
}

// Choose player sprite based on movement state and direction
void	update_player_animation(t_game *game, int frame)
{
	int	dir;

	dir = game->dir;
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

// Tick animation system and render HUD and map
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
		render_hud_moves_and_collectibles(game);
		render_hud_level_player_pos(game);
	}
}

// Wrapper used by MLX loop hook to pump animations
int	update_animation_wrapper(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->move_delay > 0)
		game->move_delay--;
	update_animation((t_game *)param);
	return (0);
}
