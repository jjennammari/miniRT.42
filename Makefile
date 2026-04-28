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
FILES = main.c tuple.c

# Fullpath for source and objects
SRC := $(addprefix $(SRC_DIR)/,$(FILES))
OBJ := $(addprefix $(BUILD_DIR)/,$(FILES:.c=.o))

# Tests Variables
TEST = test_miniRT
TEST_SRC_DIR = tests
TEST_BUILD_DIR = test_build
TEST_FILES = main.c tuple_test.c tuple.c
TEST_SRC := $(addprefix $(TEST_SRC_DIR)/,$(TEST_FILES))
TEST_OBJ := $(addprefix $(TEST_BUILD_DIR)/,$(TEST_FILES:.c=.o))

# Main Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(LIBFT):
	make -C libft all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_H) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	$(RM) $(BUILD_DIR) $(TEST_BUILD_DIR)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) $(TEST)
	make -C libft fclean

re: fclean all

# Debug Rules
debug: CFLAGS += $(GDB)
debug: fclean all

# Test Rules
test: $(TEST)

$(TEST): fclean $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TEST)
	./$(TEST)
$(TEST): fclean

$(TEST_BUILD_DIR)/%.o: $(TEST_SRC_DIR)/%.c | $(TEST_BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

.PHONY: all clean fclean re debug