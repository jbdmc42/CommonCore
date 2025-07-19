/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:47:50 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/19 11:31:12 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_state(t_game *game)
{
	game->player_sprite = game->player.idle[DIR_DOWN], game->frame_counter = 0;
	game->seconds_elapsed = 0, game->minutes_elapsed = 0, game->anim_state = 0;
	game->moving = 0, game->dir = DIR_DOWN, game->player_x = 0;
	game->player_y = 0, game->move_counter = 0;
	game->game_state = GAME_RUNNING;
	init_enemies(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\n \xE2\x88\x9F MLX or variable initialization ");
		ft_printf("failed\n");
		exit(1);
	}
	find_player_position(game);
	if (game->player_x == -1 || game->player_y == -1)
	{
		ft_printf("Error\n \xE2\x88\x9F player position not ");
		ft_printf("found in the map\n");
		exit(1);
	}
}

static void	load_all_sprites(t_game *game)
{
	load_map_and_enemies_sprites(game);
	load_player_sprites(game);
	load_collectible_sprites(game);
	load_exit_sprites(game);
}

static void	setup_hooks_and_loop(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, handle_key, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, handle_close,
		game);
	mlx_loop_hook(game->mlx, update_animation_wrapper, game);
	mlx_loop(game->mlx);
}

static void	start_game(t_game *game)
{
	int	w;
	int	h;

	h = 0, w = 0;
	while (game->map[0][w])
		w++;
	while (game->map[h])
		h++;
	game->map_width = w, game->map_height = h;
	game->win = mlx_new_window(game->mlx, w * 36, h * 36, "so_long");
	if (!game->win)
	{
		ft_printf("Error\n \xE2\x88\x9F failed to generate game window\n");
		exit(0);
	}
	load_all_sprites(game);
	render_map(game);
	setup_hooks_and_loop(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !is_valid_file_extension(argv[1]))
	{
		ft_printf("Error\n \xE2\x88\x9F invalid argument count, format or fi");
		return (ft_printf("le extension\nUsage: ./so_long <map.ber>\n"), 1);
	}
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);
	game.map_name = extract_map_name(argv[1]);
	if (!game.map_name)
		return (ft_printf("Error\n \xE2\x88\x9F failed to extract map name\n"),
		1);
	init_game_state(&game);
	if (!validate_map(&game) || !is_map_elements_valid(game.map, &game))
		return (free(game.map), 1);
	game.elements.e_total_collectibles = game.elements.e_collectible;
	start_game(&game);
	return (0);
}
