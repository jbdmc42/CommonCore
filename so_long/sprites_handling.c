/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:56:10 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 18:29:33 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_sprites(t_game *game)
{
	int	w;
	int	h;

	game->player.idle[DIR_UP] = mlx_xpm_file_to_image(game->mlx, "assets/player/Idle/Back/KnightIdleBack.xpm", &w, &h);
	game->player.idle[DIR_DOWN] = mlx_xpm_file_to_image(game->mlx, "assets/player/Idle/Front/KnightIdleFront.xpm", &w, &h);
	game->player.idle[DIR_LEFT] = mlx_xpm_file_to_image(game->mlx, "assets/player/Idle/Left/KnightIdleLeft.xpm", &w, &h);
	game->player.idle[DIR_RIGHT] = mlx_xpm_file_to_image(game->mlx, "assets/player/Idle/Right/KnightIdleRight.xpm", &w, &h);
	game->player.move1[DIR_UP] = mlx_xpm_file_to_image(game->mlx, "assets/player/Moving/Back/KnightMovingBack1.xpm", &w, &h);
	game->player.move1[DIR_DOWN] = mlx_xpm_file_to_image(game->mlx, "assets/player/Moving/Front/KnightMovingFront1.xpm", &w, &h);
	game->player.move1[DIR_LEFT] = mlx_xpm_file_to_image(game->mlx, "assets/player/Moving/Left/KnightMovingLeft1.xpm", &w, &h);
	game->player.move1[DIR_RIGHT] = mlx_xpm_file_to_image(game->mlx, "assets/player/Moving/Right/KnightMovingRight1.xpm", &w, &h);
	game->player.move2[DIR_UP] = mlx_xpm_file_to_image(game->mlx, "assets/player/Moving/Back/KnightMovingBack2.xpm", &w, &h);
	game->player.move2[DIR_DOWN] = mlx_xpm_file_to_image(game->mlx, "assets/player/Moving/Front/KnightMovingFront2.xpm", &w, &h);
	game->player.move2[DIR_LEFT] = mlx_xpm_file_to_image(game->mlx, "assets/player/Moving/Left/KnightMovingLeft2.xpm", &w, &h);
	game->player.move2[DIR_RIGHT] = mlx_xpm_file_to_image(game->mlx, "assets/player/Moving/Right/KnightMovingRight2.xpm", &w, &h);
	check_enemies_frames(game, 0);
	check_player_frames(game);
	game->dir = DIR_DOWN;
	game->player_sprite = game->player.idle[DIR_DOWN];
}

void	load_collectible_sprites(t_game *game)
{
	int	w;
	int	h;

	game->collectible.frames[0] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible1.xpm", &w, &h);
	game->collectible.frames[1] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible2.xpm", &w, &h);
	game->collectible.frames[2] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible3.xpm", &w, &h);
	game->collectible.frames[3] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible4.xpm", &w, &h);
	game->collectible.frames[4] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible5.xpm", &w, &h);
	game->collectible.frames[5] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible6.xpm", &w, &h);
	game->collectible.frames[6] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible7.xpm", &w, &h);
	game->collectible.frames[7] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible8.xpm", &w, &h);
	game->collectible.frames[8] = mlx_xpm_file_to_image(game->mlx, "assets/collectible/Collectible9.xpm", &w, &h);
}

void	load_map_and_enemies_sprites(t_game *game)
{
	int	w;
	int	h;

	game->img_ground = mlx_xpm_file_to_image(game->mlx, "assets/ground/GroundWithGrass.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/walls/Wall.xpm", &w, &h);
	game->enemies.frames[0] = mlx_xpm_file_to_image(game->mlx, "assets/enemy/Enemy1.xpm", &w, &h);
	game->enemies.frames[1] = mlx_xpm_file_to_image(game->mlx, "assets/enemy/Enemy2.xpm", &w, &h);
	game->enemies.frames[2] = mlx_xpm_file_to_image(game->mlx, "assets/enemy/Enemy3.xpm", &w, &h);
	if (!game->img_ground || !game->img_wall)
	{
		ft_printf("Error\n \xE2\x88\x9F image is NULL\n");
		return ;
	}
	check_enemies_frames(game, 1);
}

void	load_exit_sprites(t_game *game)
{
	int	w;
	int	h;

	game->exit.frames[0] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key1.xpm", &w, &h);
	game->exit.frames[1] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key2.xpm", &w, &h);
	game->exit.frames[2] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key3.xpm", &w, &h);
	game->exit.frames[3] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key4.xpm", &w, &h);
	game->exit.frames[4] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key5.xpm", &w, &h);
	game->exit.frames[5] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key6.xpm", &w, &h);
	game->exit.frames[6] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key7.xpm", &w, &h);
	game->exit.frames[7] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key8.xpm", &w, &h);
	game->exit.frames[8] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key9.xpm", &w, &h);
	game->exit.frames[9] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key10.xpm", &w, &h);
	game->exit.frames[10] = mlx_xpm_file_to_image(game->mlx, "assets/exit/Key11.xpm", &w, &h);
	check_exit_frames(game);
}
