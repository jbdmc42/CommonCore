NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
OUT_DIR = .out

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_printf.c
SRCS += print_char.c
SRCS += print_str.c
SRCS += print_int.c
SRCS += print_uint.c
#SRCS += print_hex.c
#SRCS += print_ptr.c
#SRCS += print_percent.c
SRCS += check_flagstype.c
SRCS += init_flags.c

OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(OBJS)
	cp $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(OUT_DIR)/%.o: %.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OUT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	
re: fclean all
