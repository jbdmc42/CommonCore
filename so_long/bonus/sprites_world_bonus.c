/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_world_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:36:20 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:40:41 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Generic loader for an array of XPM frames
static int	load_frames(t_game *game, void **dst, char **files, int count)
{
	int	w;
	int	h;
	int	i;

	w = 0;
	h = 0;
	i = 0;
	while (i < count)
	{
		dst[i] = mlx_xpm_file_to_image(game->mlx, files[i], &w, &h);
		if (!dst[i])
		{
			ft_printf("Error\n \xE2\x88\x9F failed to load frame %i\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

// Load ground, wall and enemy sprites (3 frames)
void	load_map_and_enemies_sprites(t_game *game)
{
	int		w;
	int		h;
	char	*files[5];

	w = 0;
	h = 0;
	set_world_files(files);
	game->img_ground = mlx_xpm_file_to_image(game->mlx, files[0], &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, files[1], &w, &h);
	if (!game->img_ground || !game->img_wall)
	{
		ft_printf("Error\n \xE2\x88\x9F failed to load map sprites\n");
		exit(1);
	}
	if (!load_enemy_frames(game, &files[2]))
		exit(1);
}

// Load exit sprites (11 frames)
void	load_exit_sprites(t_game *game)
{
	char	*files[11];

	files[0] = "textures/exit/KeyFrame1.xpm";
	files[1] = "textures/exit/KeyFrame2.xpm";
	files[2] = "textures/exit/KeyFrame3.xpm";
	files[3] = "textures/exit/KeyFrame4.xpm";
	files[4] = "textures/exit/KeyFrame5.xpm";
	files[5] = "textures/exit/KeyFrame6.xpm";
	files[6] = "textures/exit/KeyFrame7.xpm";
	files[7] = "textures/exit/KeyFrame8.xpm";
	files[8] = "textures/exit/KeyFrame9.xpm";
	files[9] = "textures/exit/KeyFrame10.xpm";
	files[10] = "textures/exit/KeyFrame11.xpm";
	if (!load_frames(game, game->exit.frames, files, 11))
		exit(1);
}

// Load collectible sprites (9 frames)
void	load_collectible_sprites(t_game *game)
{
	char	*files[9];

	files[0] = "textures/collectible/Collectible1.xpm";
	files[1] = "textures/collectible/Collectible2.xpm";
	files[2] = "textures/collectible/Collectible3.xpm";
	files[3] = "textures/collectible/Collectible4.xpm";
	files[4] = "textures/collectible/Collectible5.xpm";
	files[5] = "textures/collectible/Collectible6.xpm";
	files[6] = "textures/collectible/Collectible7.xpm";
	files[7] = "textures/collectible/Collectible8.xpm";
	files[8] = "textures/collectible/Collectible9.xpm";
	if (!load_frames(game, game->collectible.frames, files, 9))
		exit(1);
}
