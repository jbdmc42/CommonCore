/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdmc <jbdmc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:27:59 by jbdmc             #+#    #+#             */
/*   Updated: 2025/07/13 18:48:59 by jbdmc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// PRE-PROCESSOR
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "ft_printf.h"

// MACROS
# define KEY_ESC 65307					// key codes for keyboard input purposes
# define KEY_R 114

# define DIR_UP 0						// player facing direction for moving purposes
# define DIR_DOWN 1
# define DIR_LEFT 2
# define DIR_RIGHT 3

# define TILE_SIZE 36					// tile size for calculation purposes

# define GAME_RUNNING 0					// game states
# define GAME_OVER 1
# define GAME_WON 2

// PLAYER_STRUCT
typedef struct	s_player
{
	void		*idle[4];
	void		*move1[4];
	void		*move2[4];
}	t_player;

// COLLECTIBLE_STRUCT
typedef struct	s_collectible
{
	void	*frames[9];
}	t_collectible;

// ENEMIES_STRUCT
typedef struct	s_enemies
{
	void	*frames[3];
}	t_enemies;

// EXIT_STRUCT
typedef struct 	s_exit
{
	void	*frames[11];
}	t_exit;

// ELEMENTS_STRUCT
typedef struct	s_elements
{
	int		e_player;
	int		e_exit;
	int		e_collectible;
	int		e_total_collectibles;
}	t_elements;


// GAME_STRUCT
typedef struct	s_game					// main struct
{
	void			*mlx;				// MiniLibX init
	void			*win;				// window init
	char			**map;				// map init (bi-directional array pointer [X, Y])
	char			**original_map;		// original map state for reset purposes

	void			*img_wall;			// ground wall
	void			*img_ground;		// ground image
	void			*player_sprite;		// player image for direction changing purposes

	t_player		player;				// dedicated structs
	t_collectible	collectible;
	t_enemies		enemies;
	t_exit			exit;
	t_elements		elements;

	int				collectible_frame;	// current frame for the animations
	int				enemy_frame;
	int				dir;            	// player direction
	int				moving;         	// movement flag
	int				anim_state;     	// animation state (switch between Movement1 & Movement2)
	int				frame_counter;  	// animation speed controller
	int				player_x;			// player coordinates
	int				player_y;
	int				move_counter;		// counter for the moves display
	int				collected;			// number of grabbed collectibles
	int				game_state;			// game state (active = 0, lose = 1, win = 2)
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
void	check_for_enemies(t_game *game, char tile);

// 	flood_fill.c:
void 	flood_fill(char **map, int x, int y);
int		have_all_targets_been_reached(char **map);
int		count_map_lines(char **map);
void	free_map(char **map);
char	**copy_map(char **map);

// 	ft_gnl.c:
char	*ft_gnl(int fd);

// 	map_check.c:
int		is_map_rectangular(char **map);
int		is_map_surrounded(char **map);
int		validate_map_basic(char **map);
int		validate_map(t_game *game);

// 	player_handling.c:
void	check_correct_player_input(int keycode, t_game *game);
void 	find_player_position(t_game *game);
void	update_player_direction(t_game *game, int new_x, int new_y);

//	player_movement.c:
void	try_move_player(int dx, int dy, t_game *game);

// 	pre_game_checks.c:
int	 	is_valid_file_extension(const char *filename);
int		has_invalid_chars(char **map);

// 	read_map.c:
char	**read_map(const char *filepath);

// 	render_map.c:
void    render_tile(t_game *game, char tile, int x, int y);
void	render_map(t_game *game);

// 	sprite_check.c:
void	check_player_frames(t_game *game);
void	check_enemies_frames(t_game *game, int flag);
void    check_exit_frames(t_game *game);
void   	check_collectible_frames(t_game *game);

// 	sprites_handling.c:
void	load_exit_sprites(t_game *game);
void	load_map_and_enemies_sprites(t_game *game);
void	load_collectible_sprites(t_game *game);
void	load_player_sprites(t_game *game);

// 	window_and_input_handling.c:
int		handle_key(int keycode, void *param);
int		handle_close(void *param);
void	reset_game(t_game *game);

#endif
