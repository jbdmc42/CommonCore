/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:47:50 by jbdmc             #+#    #+#             */
/*   Updated: 2025/09/30 12:03:38 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_state(t_game *game)
{
	game->game_state = GAME_RUNNING;
	init_vars(game);
	init_enemies(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\n \xE2\x88\x9F MLX or variable initialization ");
		ft_printf("failed\n");
		free_all_and_exit(game);
	}
	find_player_position(game);
	if (game->player_x == -1 || game->player_y == -1)
	{
		ft_printf("Error\n \xE2\x88\x9F player position not ");
		ft_printf("found on the map\n");
		free_all_and_exit(game);
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

	h = 0;
	w = 0;
	while (game->map[0][w])
		w++;
	while (game->map[h])
		h++;
	game->map_width = w;
	game->map_height = h;
	game->win = mlx_new_window(game->mlx, w * 36, h * 36, "so_long");
	if (!game->win)
	{
		ft_printf("Error\n \xE2\x88\x9F failed to generate game window\n");
		free_all_and_exit(game);
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
		ft_printf("Error\n \xE2\x88\x9F invalid argument count, format or ");
		return (ft_printf("file extension\nUsage: ./so_long <map.ber>\n"), 1);
	}
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);
	game.map_name = extract_map_name(argv[1]);
	if (!game.map_name)
		return (ft_printf("Error\n \xE2\x88\x9F failed to extract map name\n"),
			1);
	init_game_state(&game);
	if (!validate_map(&game) || !is_map_elements_valid(game.map, &game)
		|| !is_enemy_mov_poss(game.map))
		free_all_and_exit(&game);
	game.elements.e_total_collectibles = game.elements.e_collectible;
	start_game(&game);
	return (0);
}
