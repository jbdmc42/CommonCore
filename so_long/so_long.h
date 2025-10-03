/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:27:59 by jbdmc             #+#    #+#             */
/*   Updated: 2025/10/03 03:04:48 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// PRE-PROCESSOR
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "ft_printf/ft_printf.h"

// MACROS
# define KEY_ESC 65307					// key codes for keyboard input
# define KEY_R 114

# define DIR_UP 0						// player facing direction
# define DIR_DOWN 1
# define DIR_LEFT 2
# define DIR_RIGHT 3

# define TILE_SIZE 36
# define MOVE_DELAY 500

# define GAME_RUNNING 0					// game states
# define GAME_OVER 1
# define GAME_WON 2

// PLAYER_STRUCT
typedef struct s_player
{
	void		*idle[4];
	void		*move1[4];
	void		*move2[4];
}	t_player;

// COLLECTIBLE_STRUCT
typedef struct s_collectible
{
	void	*frames[9];
}	t_collectible;

// ENEMIES_STRUCTS
typedef struct s_enemies
{
	void	*frames[3];
}	t_enemies;

typedef struct s_enemy_counter
{
	int		enemy_x;
	int		enemy_y;
	int		enemy_axis;
	int		enemy_dir;
}	t_enemy_counter;

// EXIT_STRUCT
typedef struct s_exit
{
	void	*frames[11];
}	t_exit;

// ELEMENTS_STRUCT
typedef struct s_elements
{
	int		e_player;
	int		e_exit;
	int		e_collectible;
	int		e_total_collectibles;
}	t_elements;

// GAME_STRUCT
typedef struct s_game
{
	void			*mlx;				// MiniLibX init
	void			*win;				// window init
	char			**map;				// map init
	char			**original_map;		// original map state
	void			*img_wall;			// ground wall
	void			*img_ground;		// ground image
	void			*player_sprite;		// player image
	t_player		player;				// dedicated structs
	t_collectible	collectible;
	t_enemies		enemies;
	t_exit			exit;
	t_elements		elements;
	t_enemy_counter	*enemy_counter;

	int				map_height;
	int				map_width;
	int				collectible_frame;	// current animation frames
	int				enemy_frame;
	int				exit_frame;			// exit animation frame index
	int				dir;				// player direction
	int				moving;				// movement flag
	int				anim_state;			// movement frame toggle
	int				frame_counter;		// animation speed control
	int				player_x;			// player coordinates
	int				player_y;
	int				move_counter;		// moves display counter
	int				game_state;			// game state
	int				enemy_num;			// enemies on the level
	char			*map_name;			// map name (level)
	int				move_delay;
}	t_game;

// animation_handling.c:
void	update_collectible_animation(t_game *game, int frame);
void	update_enemy_animation(t_game *game, int frame);
void	update_player_animation(t_game *game, int frame);
void	update_animation(t_game *game);
int		update_animation_wrapper(void *param);

// elements_check.c:
int		is_map_elements_valid(char **map, t_game *game);

// enemies_handling.c:
void	update_enemies(t_game *game, int frame);
void	init_enemies(t_game *game);
void	move_enemy(t_game *game, t_enemy_counter *enemy_counter);

// flood_fill.c:
void	flood_fill(char **map, int x, int y);
int		have_all_targets_been_reached(char **map);
int		count_map_lines(char **map);
void	free_map(char **map);
char	**copy_map(char **map);

// free_all_and_exit.c:
void	free_enemy_counter(t_game *game);
void	free_maps(t_game *game);
void	free_map_name(t_game *game);
void	destroy_window_and_mlx(t_game *game);
void	free_all_and_exit(t_game *game);

// ft_gnl.c:
char	*ft_gnl(int fd);

// map_check.c:
int		is_map_rectangular(char **map);
int		is_map_surrounded(char **map);
int		validate_map_basic(char **map);
int		validate_map(t_game *game);

// player_handling.c:
void	check_correct_player_input(int keycode, t_game *game);
void	find_player_position(t_game *game);
void	update_player_direction(t_game *game, int new_x, int new_y);

// player_movement.c:
void	try_move_player(int dx, int dy, t_game *game);
void	update_player_position(t_game *game, int new_x, int new_y);
void	handle_collectible(t_game *game, int x, int y);
int		is_move_valid(char tile, t_game *game);

// pre_game_checks.c:
int		is_valid_file_extension(const char *filename);
int		has_invalid_chars(char **map);

// map_io.c:
char	**read_map(const char *filepath);

// render_hud.c:
void	render_hud_moves_and_collectibles(t_game *game);
void	render_hud_level_player_pos(t_game *game);

// render_map.c:
void	render_tile(t_game *game, char tile, int x, int y);
void	render_map(t_game *game);

// sprite_check.c:
void	check_player_frames(t_game *game);
void	check_enemies_frames(t_game *game, int flag);
void	check_exit_frames(t_game *game);
void	check_collectible_frames(t_game *game);

// sprites_player.c / sprites_world.c:
void	load_exit_sprites(t_game *game);
void	load_map_and_enemies_sprites(t_game *game);
void	load_collectible_sprites(t_game *game);
void	load_player_sprites(t_game *game);

// sprites_world_utils.c:
void	set_world_files(char **files);
int		load_enemy_frames(t_game *game, char **files);

// utils_first.c:
void	player_movement_wrapper(t_game *game, char tile, int new_x, int new_y);
void	check_for_enemies(t_game *game, char tile);

// utils_second.c:
int		check_walls(char **map, int width, int height);
void	init_vars(t_game *game);
char	*prepare_moves_str(t_game *game);
void	print_idle_error(int j);

// enemies_utils.c:
int		get_ea(char c);
int		count_enemies_on_map(t_game *game);

// path_utils.c:
int		check_fd(int fd);
char	*extract_map_name(const char *filepath);

// verify_enemy_movement.c:
int		is_enemy_mov_poss(char **map);

// key_input.c:
int		handle_key(int keycode, void *param);

// window_and_input_handling.c:
int		handle_close(void *param);
int		handle_close_user(void *param);

// window_input.c (reset):
void	reset_game(t_game *game);

// free_utils.c:
void	free_player_sprites(t_game *game);
void	free_collectible_sprites(t_game *game);
void	free_map_and_enemies_sprites(t_game *game);

#endif
