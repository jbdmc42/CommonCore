/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:56:10 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/03 20:11:38 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, char *path, int x, int y)
{
	int	img_width;
	int	img_height;

	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	if (!game->img)
	{
		write(2, "Error\n", 6);
		write(1, " \xE2\x88\x9F invalid path or image\n", 27);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}
