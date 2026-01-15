# **************************************************************************** #
#                              MAKEFILE MINISHELL                              #
# **************************************************************************** #

NAME		= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -lreadline -lncurses

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I. -I$(LIBFT_DIR)

SRCS		= main.c \
			cleaning.c \
			commands_extra.c \
			commands.c \
			input_handling.c \
			parsing_helpers.c \
			parsing.c \
			setup_signal_handlers.c \
			tokenization.c

OBJS		= $(SRCS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LIBFT_A) -o $(NAME)

%.o: %.c minishell.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re