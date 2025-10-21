# **************************************************************************** #
#                              MAKEFILE MINITALK                               #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror

SRC_DIR		= src
INC_DIR		= include
PRINTF_DIR	= ft_printf
BONUS_DIR	= bonus

PRINTF_A	= $(PRINTF_DIR)/libftprintf.a
PRINTF_INC	= -I$(PRINTF_DIR)
PRINTF_LNK	= $(PRINTF_A)

INCLUDES	= -I$(INC_DIR) $(PRINTF_INC)

SRCS_SERVER	= $(SRC_DIR)/server_main.c \
			  $(SRC_DIR)/utils.c

SRCS_CLIENT	= $(SRC_DIR)/client_main.c \

BONUS_SRCS_SERVER = $(addprefix $(BONUS_DIR)/, $(notdir $(SRCS_SERVER:.c=_bonus.c)))
BONUS_SRCS_CLIENT = $(addprefix $(BONUS_DIR)/, $(notdir $(SRCS_CLIENT:.c=_bonus.c)))

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)
BONUS_OBJS_SERVER = $(BONUS_SRCS_SERVER:.c=.o)
BONUS_OBJS_CLIENT = $(BONUS_SRCS_CLIENT:.c=.o)

all: $(PRINTF_A) $(NAME_SERVER) $(NAME_CLIENT)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF_LNK) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF_LNK) -o $(NAME_CLIENT)

%.o: %.c $(INC_DIR)/minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(BONUS_OBJS_SERVER) $(BONUS_OBJS_CLIENT)
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_BONUS_SERVER) $(NAME_BONUS_CLIENT)
	@$(MAKE) -C $(PRINTF_DIR) fclean

bonus: $(PRINTF_A) $(BONUS_OBJS_SERVER) $(BONUS_OBJS_CLIENT)
	$(CC) $(CFLAGS) $(BONUS_OBJS_SERVER) $(PRINTF_LNK) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(BONUS_OBJS_CLIENT) $(PRINTF_LNK) -o $(NAME_CLIENT)

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

re: fclean all

.PHONY: all clean fclean re bonus
