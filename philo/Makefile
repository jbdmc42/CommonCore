# **************************************************************************** #
#                           MAKEFILE PHILOSOPHERS                              #
# **************************************************************************** #

NAME 		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
#CFLAGS		+= -fsanitize=thread -g
#CFLAGS		+= -fsanitize=address -g

INCLUDES	= -I.

SRCS		= main.c \
			init.c \
			philo_actions.c \
			threads.c \
			utilities.c \
			utilities_two.c \
			utilities_three.c \
			utilities_four.c \
			utilities_five.c \
			utilities_six.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
