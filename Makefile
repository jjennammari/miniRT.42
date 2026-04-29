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

# Libft
LIBFT = libft/libft.a
LIBFT_H = libft/include

# Source files
FILES = main.c tuple.c tuple_operations_1.c tuple_operations_2.c \
	helper.c test_jenna.c

# Fullpath for source and objects
SRC := $(addprefix $(SRC_DIR)/,$(FILES))
OBJ := $(addprefix $(BUILD_DIR)/,$(FILES:.c=.o))

# Main rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -lm -o $(NAME)

$(LIBFT):
	make -C libft all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_H) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	$(RM) $(BUILD_DIR)
	make -C libft clean
	make -C tests clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean
	make -C tests fclean

re: fclean all

# Debug rules
debug: CFLAGS += $(GDB)
debug: fclean all

# Test rule
test:
	make -C tests run

.PHONY: all clean fclean re debug test
