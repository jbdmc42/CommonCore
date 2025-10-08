# **************************************************************************** #
#                              MAKEFILE SO_LONG                                #
# **************************************************************************** #

NAME		= so_long
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

MLX_DIR		= minilibx
PRINTF_DIR	= ft_printf

MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
PRINTF_A	= $(PRINTF_DIR)/libftprintf.a

INCLUDES	= -I. -I$(MLX_DIR) -I$(PRINTF_DIR)

SRCS		= main.c \
			animation_handling.c \
			elements_check.c \
			enemies_handling.c \
			flood_fill.c \
			free_all_and_exit.c \
			free_utils.c \
			ft_gnl.c \
			map_check.c \
			player_handling.c \
			player_movement.c \
			pre_game_checks.c \
			map_io.c \
			render_hud.c \
			render_map.c \
			sprite_check.c \
			sprites_player.c \
			sprites_world.c \
			sprites_world_utils.c \
			utils_first.c \
			utils_second.c \
			verify_enemy_movement.c \
			window_and_input_handling.c \
			window_input.c \
			enemies_utils.c \
			path_utils.c \
			key_input.c
OBJS		= $(SRCS:.c=.o)

all: $(MLX_DIR)/libmlx.a $(PRINTF_A) $(NAME)

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(MLX_LIB) $(PRINTF_A) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re