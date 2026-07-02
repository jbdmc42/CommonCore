# **************************************************************************** #
#                              MAKEFILE MINISHELL                              #
# **************************************************************************** #

NAME		= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		+= -g3 -fsanitize=address -fno-omit-frame-pointer
LDFLAGS		= -lreadline -lncurses

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I. -I$(LIBFT_DIR)

SRCS		= main.c \
			cd.c \
			cleaning.c \
			commands_builtin.c \
			commands_extra_two.c \
			commands_extra.c \
			commands_path_exec.c \
			commands_exec_direct.c \
			commands.c \
			echo.c \
			env.c \
			env_helpers.c \
			exec_error.c \
			exit.c \
			export_helpers_two.c \
			export_helpers.c \
			export.c \
			ft_getline_fd.c \
			ft_getline.c \
			ft_mkstemp_helpers.c \
			ft_mkstemp.c \
			ft_lseek.c \
			ft_lsttochpp.c \
			input_handling.c \
			main_helpers.c \
			parsing_helpers_four.c \
			parsing_helpers_three.c \
			parsing_helpers_two.c \
			parsing_helpers.c \
			parsing.c \
			pipes_helpers_four.c \
			pipes_helpers_three.c \
			pipes_helpers_two.c \
			pipes_helpers.c \
			pipes.c \
			pwd.c \
			quote_handling.c \
			redir_helpers_five.c \
			redir_helpers_four.c \
			redir_helpers_three.c \
			redir_helpers_two.c \
			redir_helpers.c \
			redir_process_helpers.c \
			redir_process.c \
			redir_utils.c \
			redir.c \
			setup_signal_handlers.c \
			tokenization.c \
			unset.c \
			utilities_three.c \
			utilities_two.c \
			utilities.c

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

#valgrind: 
#	@echo "{\n   leak readline\n   Memcheck:Leak\n...\n   fun:readline\n}\n{\n   leak add_history\n   Memcheck:Leak\n...\n   fun:add_history\n}" > readline.supp
#	@valgrind --suppressions=readline.supp --leak-check=full -s ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
