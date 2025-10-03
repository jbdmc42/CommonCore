# **************************************************************************** #
#                             MAKEFILE PUSH_SWAP                               #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

PRINTF_DIR	= ft_printf
PRINTF_A	= $(PRINTF_DIR)/libftprintf.a

INCLUDES	= -I. -I$(PRINTF_DIR)

SRCS		= ft_atol.c \
			ft_free.c \
			ft_print.c \
			main_algorithm.c \
			main.c \
			movement_calculator.c \
			pricing_algorithm.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			sort_check.c \
			sorting_algorithm.c \
			special_cases.c \
			stack_init.c \
			swap.c \
			tiny_cases.c \

OBJS		= $(SRCS:.c=.o)

all: $(PRINTF_A) $(NAME)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(PRINTF_A) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
