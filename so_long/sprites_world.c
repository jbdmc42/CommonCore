/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:36:20 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/03 02:41:02 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!load_frames(game, game->exit.frames, files, 11))
		exit(1);
}

// Load collectible sprites (9 frames)
void	load_collectible_sprites(t_game *game)
{
	char	*files[9];

	files[0] = "a/collectible/Collectible1.xpm";
	files[1] = "a/collectible/Collectible2.xpm";
	files[2] = "a/collectible/Collectible3.xpm";
	files[3] = "a/collectible/Collectible4.xpm";
	files[4] = "a/collectible/Collectible5.xpm";
	files[5] = "a/collectible/Collectible6.xpm";
	files[6] = "a/collectible/Collectible7.xpm";
	files[7] = "a/collectible/Collectible8.xpm";
	files[8] = "a/collectible/Collectible9.xpm";
	if (!load_frames(game, game->collectible.frames, files, 9))
		exit(1);
}
