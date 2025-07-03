NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT_A = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_printf.c
SRCS += print_char.c
SRCS += print_str.c
SRCS += print_int.c
SRCS += print_uint.c
SRCS += print_hex.c
SRCS += print_ptr.c
SRCS += check_flagstype.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_A): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(LIBFT_A) $(LIBFT_DIR)/*.o

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
