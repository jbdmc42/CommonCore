NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm

SRCS = ft_printf.c
SRCS += print_char.c
SRCS += print_str.c
SRCS += print_int.c
SRCS += print_uint.c
SRCS += print_hex.c
SRCS += print_ptr.c
SRCS += print_percent.c
SRCS += check_flagstype.c

OBJS = $(SRCS:.c=.o)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(OBJS)
	cp $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	
re: fclean all
