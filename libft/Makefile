NAME = libft.a
SRCS = 
OBJS = 
INCS = 
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I $(INCS) -c $(SRCS)	

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all
