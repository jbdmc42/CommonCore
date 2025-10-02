/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:56:10 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/30 17:09:34 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_player_array(t_game *game, void **array, char **files, int w, int h)
{
	int	i;

	w = 0;
	h = 0;
	i = 0;
	while (i < 4)
	{
		array[i] = mlx_xpm_file_to_image(game->mlx, files[i], &w, &h);
		if (!array[i])
		{
			ft_printf("Error\n \xE2\x88\x9F failed to load player sprite %i\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

void	load_player_sprites(t_game *game)
{
	int		w;
	int		h;
	char	*idle_files[4];
	char	*move1_files[4];
	char	*move2_files[4];

	w = 0;
	h = 0;
	idle_files[0] = "a/player/Idle/Back/KnightIdleBack.xpm";
	idle_files[1] = "a/player/Idle/Front/KnightIdleFront.xpm";
	idle_files[2] = "a/player/Idle/Left/KnightIdleLeft.xpm";
	idle_files[3] = "a/player/Idle/Right/KnightIdleRight.xpm";
	move1_files[0] = "a/player/Moving/Back/KnightMovingBack1.xpm";
	move1_files[1] = "a/player/Moving/Front/KnightMovingFront1.xpm";
	move1_files[2] = "a/player/Moving/Left/KnightMovingLeft1.xpm";
	move1_files[3] = "a/player/Moving/Right/KnightMovingRight1.xpm";
	move2_files[0] = "a/player/Moving/Back/KnightMovingBack2.xpm";
	move2_files[1] = "a/player/Moving/Front/KnightMovingFront2.xpm";
	move2_files[2] = "a/player/Moving/Left/KnightMovingLeft2.xpm";
	move2_files[3] = "a/player/Moving/Right/KnightMovingRight2.xpm";
	if (!load_player_array(game, game->player.idle, idle_files, w, h)
		|| !load_player_array(game, game->player.move1, move1_files, w, h)
		|| !load_player_array(game, game->player.move2, move2_files, w, h))
		exit(1);
	game->dir = DIR_DOWN;
	game->player_sprite = game->player.idle[DIR_DOWN];
}

void	load_collectible_sprites(t_game *game)
{
	int		w;
	int		h;
	char	*files[9];
	int		i;

	w = 0;
	h = 0;
	files[0] = "a/collectible/Collectible1.xpm";
	files[1] = "a/collectible/Collectible2.xpm";
	files[2] = "a/collectible/Collectible3.xpm";
	files[3] = "a/collectible/Collectible4.xpm";
	files[4] = "a/collectible/Collectible5.xpm";
	files[5] = "a/collectible/Collectible6.xpm";
	files[6] = "a/collectible/Collectible7.xpm";
	files[7] = "a/collectible/Collectible8.xpm";
	files[8] = "a/collectible/Collectible9.xpm";
	i = 0;
	while (i < 9)
	{
		game->collectible.frames[i] = mlx_xpm_file_to_image(game->mlx,
			files[i], &w, &h);
		if (!game->collectible.frames[i])
		{
			ft_printf("Error\n \xE2\x88\x9F failed to load collectible ");
			ft_printf("frame %i\n", i);
			exit(1);
		}
		i++;
	}
}

void	load_map_and_enemies_sprites(t_game *game)
{
	int		w;
	int		h;
	char	*files[5];

	w = 0;
	h = 0;
	files[0] = "a/ground/Ground.xpm";
	files[1] = "a/walls/Wall.xpm";
	files[2] = "a/enemy/Enemy1.xpm";
	files[3] = "a/enemy/Enemy2.xpm";
	files[4] = "a/enemy/Enemy3.xpm";
	game->img_ground = mlx_xpm_file_to_image(game->mlx, files[0], &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, files[1], &w, &h);
	game->enemies.frames[0] = mlx_xpm_file_to_image(game->mlx, files[2], &w, &h);
	game->enemies.frames[1] = mlx_xpm_file_to_image(game->mlx, files[3], &w, &h);
	game->enemies.frames[2] = mlx_xpm_file_to_image(game->mlx, files[4], &w, &h);
	if (!game->img_ground || !game->img_wall || !game->enemies.frames[0]
		|| !game->enemies.frames[1] || !game->enemies.frames[2])
	{
		ft_printf("Error\n \xE2\x88\x9F failed to load map/enemy sprites\n");
		exit(1);
	}
}

void	load_exit_sprites(t_game *game)
{
	int		w;
	int		h;
	char	*files[11];
	int		i;

	w = 0;
	h = 0;
	files[0] = "a/1.xpm";
	files[1] = "a/2.xpm";
	files[2] = "a/3.xpm";
	files[3] = "a/4.xpm";
	files[4] = "a/5.xpm";
	files[5] = "a/6.xpm";
	files[6] = "a/7.xpm";
	files[7] = "a/8.xpm";
	files[8] = "a/9.xpm";
	files[9] = "a/10.xpm";
	files[10] = "a/11.xpm";
	i = 0;
	while (i < 11)
	{
		game->exit.frames[i] = mlx_xpm_file_to_image(game->mlx, 
			files[i], &w, &h);
		if (!game->exit.frames[i])
		{
			ft_printf("Error\n \xE2\x88\x9F failed to load exit frame %i\n", i);
			exit(1);
		}
		i++;
	}
}
