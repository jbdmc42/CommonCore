/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_world_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 06:25:00 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/16 14:40:47 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Set file paths for world (ground, wall, enemies)
void	set_world_files(char **files)
{
	files[0] = "textures/ground/Ground.xpm";
	files[1] = "textures/walls/Wall.xpm";
	files[2] = "textures/enemy/Enemy1.xpm";
	files[3] = "textures/enemy/Enemy2.xpm";
	files[4] = "textures/enemy/Enemy3.xpm";
}

// Load the 3 enemy frames from an array of 3 file paths
int	load_enemy_frames(t_game *game, char **files)
{
	int	w;
	int	h;
	int	i;

	w = 0;
	h = 0;
	i = 0;
	while (i < 3)
	{
		game->enemies.frames[i] = mlx_xpm_file_to_image(
				game->mlx, files[i], &w, &h);
		if (!game->enemies.frames[i])
		{
			ft_printf("Error\n \xE2\x88\x9F failed to load enemy frame %i\n",
				i);
			return (0);
		}
		i++;
	}
	return (1);
}
