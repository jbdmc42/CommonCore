/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaobarb <joaobarb@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:35:00 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/08 14:22:17 by joaobarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Fill arrays with player sprite file paths
static void	set_player_files(char **idle, char **move1, char **move2)
{
	idle[0] = "textures/player/Idle/Back/KnightIdleBack.xpm";
	idle[1] = "textures/player/Idle/Front/KnightIdleFront.xpm";
	idle[2] = "textures/player/Idle/Left/KnightIdleLeft.xpm";
	idle[3] = "textures/player/Idle/Right/KnightIdleRight.xpm";
	move1[0] = "textures/player/Moving/Back/KnightMovingBack1.xpm";
	move1[1] = "textures/player/Moving/Front/KnightMovingFront1.xpm";
	move1[2] = "textures/player/Moving/Left/KnightMovingLeft1.xpm";
	move1[3] = "textures/player/Moving/Right/KnightMovingRight1.xpm";
	move2[0] = "textures/player/Moving/Back/KnightMovingBack2.xpm";
	move2[1] = "textures/player/Moving/Front/KnightMovingFront2.xpm";
	move2[2] = "textures/player/Moving/Left/KnightMovingLeft2.xpm";
	move2[3] = "textures/player/Moving/Right/KnightMovingRight2.xpm";
}

// Load an array of 4 player sprites for the given files
static int	load_player_array(t_game *game, void **array, char **files)
{
	int	w;
	int	h;
	int	i;

	w = 0;
	h = 0;
	i = 0;
	while (i < 4)
	{
		array[i] = mlx_xpm_file_to_image(game->mlx, files[i], &w, &h);
		if (!array[i])
		{
			ft_printf("Error\n \xE2\x88\x9F failed to load player sprite %i\n",
				i);
			return (0);
		}
		i++;
	}
	return (1);
}

// Load all player idle and movement sprites
void	load_player_sprites(t_game *game)
{
	char	*idle_files[4];
	char	*move1_files[4];
	char	*move2_files[4];

	set_player_files(idle_files, move1_files, move2_files);
	if (!load_player_array(game, game->player.idle, idle_files)
		|| !load_player_array(game, game->player.move1, move1_files)
		|| !load_player_array(game, game->player.move2, move2_files))
		exit(1);
	game->dir = DIR_DOWN;
	game->player_sprite = game->player.idle[DIR_DOWN];
}
