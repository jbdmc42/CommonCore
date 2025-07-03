/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:47:50 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/03 23:41:42 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init(); // initializes the MiniLibX
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "so_long");
	if (!game.win)
		return (1);
	game.img = NULL;
	put_image(&game, "assets/walls/Wall.xpm", 0, 0);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game); // 17 corresponds to the window "X" closing action
	mlx_loop(game.mlx);
	return (0);
}
