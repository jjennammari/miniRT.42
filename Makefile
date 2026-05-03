NAME = miniRT

# Tools
CC = cc
CFLAGS = -Wall -Werror -Wextra
GDB = -g
RM = rm -rf

# Directories
INCLUDE_DIR = ./include
BUILD_DIR = build
SRC_DIR = src
MLX_DIR = minilibx-linux

# Libft
LIBFT = libft/libft.a
LIBFT_H = libft/include

# Source files
FILES = main.c tuple.c tuple_operations_1.c tuple_operations_2.c \
	helper.c test_jenna.c setup_rt.c

# Fullpath for source and objects
SRC := $(addprefix $(SRC_DIR)/,$(FILES))
OBJ := $(addprefix $(BUILD_DIR)/,$(FILES:.c=.o))

# Main rules
all: $(NAME)

$(NAME): mlx $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -O3 -o $(NAME)

$(LIBFT):
	make -C libft all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_H) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

mlx:
	make -C $(MLX_DIR)

clean:
	$(RM) $(BUILD_DIR)
	make -C libft clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

# Debug rules
debug: CFLAGS += $(GDB)
debug: fclean all

# Test rule
test:
	make -C tests run

.PHONY: all clean fclean re debug test
