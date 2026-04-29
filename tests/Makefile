NAME = test_miniRT

# Parent Directory References
ROOT_DIR = ..
SRC_DIR = $(ROOT_DIR)/src
INCLUDE_DIR = $(ROOT_DIR)/include
LIBFT_DIR = $(ROOT_DIR)/libft
LIBFT_H = $(LIBFT_DIR)/include

# Local Build Directory
BUILD_DIR = build

# Tools
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

# Files
TEST_FILES = test.c test_tuple.c
PROJ_FILES = $(filter-out main.c, $(shell ls ../src))

# Object targets
TEST_OBJ = $(addprefix $(BUILD_DIR)/, $(TEST_FILES:.c=.o))
PROJ_OBJ = $(addprefix $(BUILD_DIR)/, $(PROJ_FILES:.c=.o))
OBJ = $(TEST_OBJ) $(PROJ_OBJ)

# Rules
all: $(NAME)

$(NAME): $(ROOT_DIR)/$(LIBFT_DIR)/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -lm -o $(NAME)

# Libft
$(ROOT_DIR)/$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) all

# Compile tests
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_H) -c $< -o $@

# Compile project
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_H) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build and run
run: all
	valgrind ./$(NAME)
	make fclean

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all run clean fclean re