NAME        = miniRT

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -std=gnu17
LDFLAGS     = -lm -lXext -lX11 -lz

GNL_DIR		= include/get_next_line
GNL_A		= $(GNL_DIR)/get_next_line.a

LIBFT_DIR   = include/libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

MLX_DIR     = include/minilibx
MLX_A       = $(MLX_DIR)/libmlx.a

INCLUDES    = -I./include -I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS        = src/main.c \
			src/cleanup/free.c \
			src/input_validation/extension.c \
			src/parser/extract_objs.c \
			src/parser/extract_scene.c \
			src/parser/scene_parser.c \
			src/program_execution/body.c \
			src/program_execution/camera_rays.c \
			src/program_execution/initialization.c \
			src/program_execution/intersect.c \
			src/program_execution/lighting.c \
			src/program_execution/rotation.c \
			src/program_execution/scene_renderer.c \
			src/program_execution/scene_rendering_helpers.c \
			src/program_execution/transform.c \
			src/tools/ft_def_atod.c \
			src/tools/ft_def_atoi.c \
			src/tools/vector_math1.c \
			src/tools/vector_math2.c

OBJS        = $(SRCS:.c=.o)


all: $(GNL_A) $(LIBFT_A) $(MLX_A) $(NAME)
	@printf "\n\033[1;32m✓ MiniRT build successful!\033[0m\n\n"


$(GNL_A):
	@printf "\033[1;34m[1/4]\033[0m Building GetNextLine...\n"
	@$(MAKE) -s -C $(GNL_DIR)
	@printf "\033[1;32m✓ GetNextLine complete\033[0m\n\n"


$(LIBFT_A):
	@printf "\033[1;34m[2/4]\033[0m Building Libft...\n"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@printf "\033[1;32m✓ Libft complete\033[0m\n\n"


$(MLX_A):
	@printf "\033[1;34m[3/4]\033[0m Building MiniLibX...\n"
	@$(MAKE) -s -C $(MLX_DIR) >/dev/null 2>&1 || test -f $(MLX_A)
	@printf "\033[1;32m✓ MiniLibX complete\033[0m\n\n"


$(NAME): $(OBJS)
	@printf "\033[1;34m[4/4]\033[0m Building MiniRT...\n"
	@$(CC) $(OBJS) $(GNL_A) $(LIBFT_A) $(MLX_A) $(LDFLAGS) -o $(NAME)
	@printf "\033[1;32m✓ MiniRT complete\033[0m\n\n"


%.o: %.c include/minirt.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	@printf "\033[1;33mCleaning object files...\033[0m\n"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(GNL_DIR) clean
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@printf "\n\033[1;32m✓ Clean complete\033[0m\n\n"


fclean: clean
	@printf "\033[1;33mRemoving executable and libraries...\033[0m\n"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(GNL_DIR) fclean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@printf "\n\033[1;32m✓ Full clean complete\033[0m\n\n"


re: fclean all


valgrind:
	@echo "{\n   leak readline\n   Memcheck\:Leak\n...\n   fun\:readline\n}\n{\n   leak add_history\n   Memcheck\:Leak\n...\n   fun\:add_history\n}" > readline.supp
	@valgrind --suppressions=readline.supp --leak-check=full -s ./$(NAME)


.PHONY: all clean fclean re valgrind