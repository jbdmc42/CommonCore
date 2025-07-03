# **************************************************************************** #
#                              MAKEFILE SO_LONG                                #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

MLX_DIR		= minilibx
PRINTF_DIR	= ft_printf

MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
PRINTF_A	= $(PRINTF_DIR)/libftprintf.a

INCLUDES	= -I. -I$(MLX_DIR) -I$(PRINTF_DIR)

SRCS		= main.c img_handling.c so_long_gnl.c so_long_utils.c
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
